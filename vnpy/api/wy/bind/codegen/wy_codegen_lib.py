import clang.cindex
import sys
#libclang installed via conda seems imcompatible?
#clang.cindex.Config.set_library_file('c:/Users/lunan/miniconda3/pkgs/libclang-11.0.0-default_h5c34c98_2/Library/bin/libclang.dll')
clang.cindex.Config.set_library_file(r'C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\Llvm\x64\bin\libclang.dll')

from clang.cindex import CursorKind, TypeKind, Type

def more_dent(out_func, dent_level=1, dent='  '):
    def decorated(line):
        out_func(dent*dent_level + line)
    return decorated


def use_py_bytes(t: Type):
    """Return true if the Cxx type should be bind to py bytes
    """
    return t.kind == TypeKind.CONSTANTARRAY and t.get_array_element_type().kind == TypeKind.CHAR_S


def collect_enum(c, out_func):
    assert c.kind == CursorKind.ENUM_DECL
    dent_out = more_dent(out_func)
    if c.spelling == '':
        for v in c.get_children():
            if v.kind == CursorKind.ENUM_CONSTANT_DECL:
                out_func(f'm.attr("{v.spelling}") = static_cast<int>({v.spelling});')
    else:
        out_func(f'py::enum_<{c.spelling}>(m, "{c.spelling}")')
        for v in c.get_children():
            if v.kind == CursorKind.ENUM_CONSTANT_DECL:
                dent_out(f'.value("{v.spelling}", {c.spelling}::{v.spelling})')
        dent_out('.export_values();')
    dent_out('')

        
def collect_readonly_field(node, out_func):
    for v in node.get_children():
        if v.kind == CursorKind.FIELD_DECL:
            if use_py_bytes(v.type):
                out_func(f'.def_property_readonly("b{v.spelling}", [](const {node.spelling}& self) {{return self.{v.spelling};}})')
            else:
                out_func(f'.def_readonly("{v.spelling}", &{node.spelling}::{v.spelling})')


def collect_ctor(c, out_func):
    """ append default constructor, copy constructor
    """
    for v in c.get_children():
        if v.kind == CursorKind.CONSTRUCTOR:
            if v.is_default_constructor():
                out_func(f'.def(py::init<>())')
            elif v.is_copy_constructor():
                out_func(f'.def(py::init<{c.spelling}>())')
            else:
                assert False


def collect_cxx_method(c, out_func):
    for child in c.get_children():
        if child.kind == CursorKind.PARM_DECL:
            pass
        
def collect_base_struct(c, out_func):
    """ doesn't handle cxx access specifier and derived class
    """
    assert c.kind == CursorKind.STRUCT_DECL
    out_func(f'py::class_<{c.spelling}>(m, "{c.spelling}")')
    collect_ctor(c, more_dent(out_func))
    collect_cxx_method(c, more_dent(out_func))
    collect_readonly_field(c, more_dent(out_func))
    out_func(';')


        
def collect_pybind(filepath, module_name, out_func=print, including_filenames = [], open_bracket=True):
    # top-level enum/struct, no namespace
    # not a recursive function
    import os
    index = clang.cindex.Index.create()
    filename = os.path.basename(filepath)
    tu = index.parse(filepath, args='-x c++ --std=c++11'.split())
    # diag
    for d in tu.diagnostics:
        if d.severity > clang.cindex.Diagnostic.Warning:
            out_func(f'{d}')
            return

    tu_cursor = tu.cursor
    next_out_func = more_dent(out_func)
    def look_at_main_file(node):
        if node.location.file.name != filepath:
            if os.path.basename(node.location.file.name) not in including_filenames:
                return
        if node.kind == CursorKind.ENUM_DECL:
            collect_enum(node, out_func)
        elif node.kind == CursorKind.STRUCT_DECL:
            collect_base_struct(node, out_func)
    out_func(f'// Generated from {filepath}')          
    out_func(f'PYBIND11_MODULE({module_name}, m)''{')
    for t in tu_cursor.get_children():
        look_at_main_file(t)
    if not open_bracket:
        out_func('}')