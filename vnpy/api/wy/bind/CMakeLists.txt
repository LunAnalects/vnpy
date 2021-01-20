project(wy_md LANGUAGES CXX)
plan21_include_dirs("quote_clt/zhcong/include")

pybind11_add_module(wy_md wy_md.cpp py_wy_md.cpp)
target_link_libraries(wy_md PRIVATE ${WY_STATIC})

#[[
set(GENERATED_PYBINDING_HDR ${CMAKE_CURRENT_SOURCE_DIR}/py_wy_md.cpp)
add_custom_command(
  OUTPUT ${GENERATED_PYBINDING_HDR}
  COMMAND C:/Users/lunan/miniconda3/envs/plan21_dev/python
  ARGS    -m cogapp -o ${GENERATED_PYBINDING_HDR} ${CMAKE_CURRENT_SOURCE_DIR}/codegen_header/template_py_wy_md_quote.cpp
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/codegen_header/wy_codegen_lib.py
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/codegen_header/template_py_wy_md_quote.cpp
)
add_custom_target(
  pybinding_codegen
  DEPENDS ${GENERATED_PYBINDING_HDR}
)
add_dependencies(wy_md pybinding_codegen)
]]