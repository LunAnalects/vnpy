#ifndef CODEGEN__PLAN21_WY_MD_QUOTE_H_
#define CODEGEN__PLAN21_WY_MD_QUOTE_H_
#pragma once

/*[[[cog
import datetime
import sys
cog.outl(f'// This file is auto generated at {datetime.datetime.now()}, command={sys.argv[1:]}')
]]]*/
/*[[[end]]]*/

#include <pybind11/pybind11.h>
#include "quote_defs.h"
#include "quote/wyquote_struct.h"
#include "py_wy_md.h"

namespace py = pybind11;

/*[[[cog
import cog
import clang.cindex
from wy_codegen_lib import collect_pybind

index = clang.cindex.Index.create()
wq_cursor = './wyquote_struct.h'
module_name = 'wy_md'
collect_pybind(wq_cursor, module_name, out_func = cog.outl, including_filenames=['quote_defs.h'])
]]]*/
/*[[[end]]]*/

py::class_<WyMd, PyWyMd>(m, "py_wymd")
.def(py::init<>())
.def("connect", &WyMd::connect)
.def("subscribe", &WyMd::subscribe)
.def("unsubscribe", &WyMd::subscribe)
.def("OnConnect", &WyMd::OnConnect)
.def("OnCodeList", &WyMd::OnCodeList)
.def("OnIndRealData", &WyMd::OnIndRealData)
.def("OnSecRealDataL1", &WyMd::OnSecRealDataL1)
.def("OnSecRealDataL2", &WyMd::OnSecRealDataL2)
.def("OnFutRealDataL1", &WyMd::OnFutRealDataL1)
.def("OnFutRealDataL2", &WyMd::OnFutRealDataL2)
.def("OnSecTransaction", &WyMd::OnSecTransaction)
.def("OnSecOrder", &WyMd::OnSecOrder)
.def("OnSecOrderQueue", &WyMd::OnSecOrderQueue)
.def("OnSecMinK", &WyMd::OnSecMinK)
.def("OnOptFutMinK", &WyMd::OnOptFutMinK)
.def("OnIndRealDataByShares", &WyMd::OnIndRealDataByShares)
.def("OnIndRealDataByWeights", &WyMd::OnIndRealDataByWeights)
.def("OnServerQuoteDisconnected", &WyMd::OnServerQuoteDisconnected)
.def("OnServerQuoteReconnected", &WyMd::OnServerQuoteReconnected);
}
#endif // CODEGEN__PLAN21_WY_MD_QUOTE_H_