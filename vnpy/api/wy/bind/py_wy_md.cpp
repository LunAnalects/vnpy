#ifndef CODEGEN__PLAN21_WY_MD_QUOTE_H_
#define CODEGEN__PLAN21_WY_MD_QUOTE_H_
#pragma once

/*[[[cog
import datetime
import sys
cog.outl(f'// This file is auto generated at {datetime.datetime.now()}, command={sys.argv[1:]}')
]]]*/
// This file is auto generated at 2021-01-20 21:37:45.443560, command=['-o', '..\\py_wy_md.cpp', 'template_py_wy_md.cpp']
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
// Generated from ./wyquote_struct.h
PYBIND11_MODULE(wy_md, m){
py::enum_<CtSecType>(m, "CtSecType")
  .value("Ct_ST_NotSupport", CtSecType::Ct_ST_NotSupport)
  .value("Ct_ST_Stk", CtSecType::Ct_ST_Stk)
  .value("Ct_ST_Fut", CtSecType::Ct_ST_Fut)
  .value("Ct_ST_CommodityOpt", CtSecType::Ct_ST_CommodityOpt)
  .value("Ct_ST_ETFOpt", CtSecType::Ct_ST_ETFOpt)
  .export_values();
  
py::enum_<CtProductClass>(m, "CtProductClass")
  .value("Ct_PC_NotSupport", CtProductClass::Ct_PC_NotSupport)
  .value("Ct_PC_Futures", CtProductClass::Ct_PC_Futures)
  .value("Ct_PC_Options", CtProductClass::Ct_PC_Options)
  .value("Ct_PC_Combination", CtProductClass::Ct_PC_Combination)
  .value("Ct_PC_Spot", CtProductClass::Ct_PC_Spot)
  .value("Ct_PC_EFP", CtProductClass::Ct_PC_EFP)
  .value("Ct_PC_SpotOption", CtProductClass::Ct_PC_SpotOption)
  .export_values();
  
py::enum_<CtOptCPType>(m, "CtOptCPType")
  .value("Ct_OCT_no", CtOptCPType::Ct_OCT_no)
  .value("Ct_OCT_Call", CtOptCPType::Ct_OCT_Call)
  .value("Ct_OCT_Put", CtOptCPType::Ct_OCT_Put)
  .export_values();
  
py::enum_<CtOptStrikeModeType>(m, "CtOptStrikeModeType")
  .value("Ct_OCT_STM_NotSupport", CtOptStrikeModeType::Ct_OCT_STM_NotSupport)
  .value("Ct_OCT_STM_Continental", CtOptStrikeModeType::Ct_OCT_STM_Continental)
  .value("Ct_OCT_STM_American", CtOptStrikeModeType::Ct_OCT_STM_American)
  .value("Ct_OCT_STM_Bermuda", CtOptStrikeModeType::Ct_OCT_STM_Bermuda)
  .export_values();
  
py::enum_<CtCombtType>(m, "CtCombtType")
  .value("Ct_COMBT_NotSupport", CtCombtType::Ct_COMBT_NotSupport)
  .value("Ct_COMBT_Futures", CtCombtType::Ct_COMBT_Futures)
  .value("Ct_COMBT_BUL", CtCombtType::Ct_COMBT_BUL)
  .value("Ct_COMBT_BER", CtCombtType::Ct_COMBT_BER)
  .value("Ct_COMBT_STD", CtCombtType::Ct_COMBT_STD)
  .value("Ct_COMBT_STG", CtCombtType::Ct_COMBT_STG)
  .value("Ct_COMBT_PRT", CtCombtType::Ct_COMBT_PRT)
  .value("Ct_COMBT_CLD", CtCombtType::Ct_COMBT_CLD)
  .export_values();
  
m.attr("OK_BLK_Unknown") = static_cast<int>(OK_BLK_Unknown);
m.attr("OK_BLK_Index_SH") = static_cast<int>(OK_BLK_Index_SH);
m.attr("OK_BLK_Index_SZ") = static_cast<int>(OK_BLK_Index_SZ);
m.attr("OK_BLK_Stk_SHA") = static_cast<int>(OK_BLK_Stk_SHA);
m.attr("OK_BLK_Stk_SZA") = static_cast<int>(OK_BLK_Stk_SZA);
m.attr("OK_BLK_Stk_S") = static_cast<int>(OK_BLK_Stk_S);
m.attr("OK_BLK_Stk_G") = static_cast<int>(OK_BLK_Stk_G);
m.attr("OK_BLK_Stk_SHB") = static_cast<int>(OK_BLK_Stk_SHB);
m.attr("OK_BLK_Stk_SZB") = static_cast<int>(OK_BLK_Stk_SZB);
m.attr("OK_BLK_Stk_SHFJ") = static_cast<int>(OK_BLK_Stk_SHFJ);
m.attr("OK_BLK_Stk_SZFJ") = static_cast<int>(OK_BLK_Stk_SZFJ);
m.attr("OK_BLK_Stk_SCI") = static_cast<int>(OK_BLK_Stk_SCI);
m.attr("OK_BLK_Stk_ST") = static_cast<int>(OK_BLK_Stk_ST);
m.attr("OK_BLK_Fund_LOF") = static_cast<int>(OK_BLK_Fund_LOF);
m.attr("OK_BLK_Fund_ETF") = static_cast<int>(OK_BLK_Fund_ETF);
m.attr("OK_BLK_Repo_NA") = static_cast<int>(OK_BLK_Repo_NA);
m.attr("OK_BLK_Fut_CFFEX_Index") = static_cast<int>(OK_BLK_Fut_CFFEX_Index);
m.attr("OK_BLK_Fut_CFFEX_T") = static_cast<int>(OK_BLK_Fut_CFFEX_T);
m.attr("OK_BLK_Fut_DCE") = static_cast<int>(OK_BLK_Fut_DCE);
m.attr("OK_BLK_Fut_CZCE") = static_cast<int>(OK_BLK_Fut_CZCE);
m.attr("OK_BLK_Fut_SHFE") = static_cast<int>(OK_BLK_Fut_SHFE);
m.attr("OK_BLK_Fut_INE") = static_cast<int>(OK_BLK_Fut_INE);
m.attr("OK_BLK_Option_ETF50") = static_cast<int>(OK_BLK_Option_ETF50);
m.attr("OK_BLK_CUSTOM") = static_cast<int>(OK_BLK_CUSTOM);
  
py::class_<OK_CODE>(m, "OK_CODE")
  .def(py::init<>())
  .def(py::init<OK_CODE>())
  .def_property_readonly("bInstrumentID", [](const OK_CODE& self) {return self.InstrumentID;})
  .def_property_readonly("bInstrumentName", [](const OK_CODE& self) {return self.InstrumentName;})
  .def_readonly("blkType", &OK_CODE::blkType)
;
py::class_<OK_OPTIONCODE>(m, "OK_OPTIONCODE")
  .def(py::init<>())
  .def(py::init<OK_OPTIONCODE>())
  .def_property_readonly("bInstrumentID", [](const OK_OPTIONCODE& self) {return self.InstrumentID;})
  .def_property_readonly("bInstrumentName", [](const OK_OPTIONCODE& self) {return self.InstrumentName;})
  .def_readonly("blkType", &OK_OPTIONCODE::blkType)
  .def_property_readonly("bExchangeID", [](const OK_OPTIONCODE& self) {return self.ExchangeID;})
  .def_property_readonly("bUnderlyingInstrID", [](const OK_OPTIONCODE& self) {return self.UnderlyingInstrID;})
  .def_readonly("CPType", &OK_OPTIONCODE::CPType)
  .def_readonly("strikeModeType", &OK_OPTIONCODE::strikeModeType)
  .def_readonly("PriceTick", &OK_OPTIONCODE::PriceTick)
  .def_readonly("StrikePrice", &OK_OPTIONCODE::StrikePrice)
  .def_readonly("VolumeMultiple", &OK_OPTIONCODE::VolumeMultiple)
  .def_readonly("OpenDate", &OK_OPTIONCODE::OpenDate)
  .def_readonly("ExpireDate", &OK_OPTIONCODE::ExpireDate)
;
py::class_<OK_FUT_CODE>(m, "OK_FUT_CODE")
  .def(py::init<>())
  .def(py::init<OK_FUT_CODE>())
  .def_property_readonly("bExchangeID", [](const OK_FUT_CODE& self) {return self.ExchangeID;})
  .def_property_readonly("bInstrumentID", [](const OK_FUT_CODE& self) {return self.InstrumentID;})
  .def_property_readonly("bInstrumentName", [](const OK_FUT_CODE& self) {return self.InstrumentName;})
  .def_property_readonly("bProductID", [](const OK_FUT_CODE& self) {return self.ProductID;})
  .def_readonly("ProductClass", &OK_FUT_CODE::ProductClass)
  .def_readonly("VolumeMultiple", &OK_FUT_CODE::VolumeMultiple)
  .def_readonly("PriceTick", &OK_FUT_CODE::PriceTick)
  .def_readonly("OpenDate", &OK_FUT_CODE::OpenDate)
  .def_readonly("ExpireDate", &OK_FUT_CODE::ExpireDate)
  .def_readonly("IsTrading", &OK_FUT_CODE::IsTrading)
  .def_readonly("CombinationType", &OK_FUT_CODE::CombinationType)
  .def_readonly("blkType", &OK_FUT_CODE::blkType)
;
py::class_<OK_FUT_OPTIONCODE>(m, "OK_FUT_OPTIONCODE")
  .def(py::init<>())
  .def(py::init<OK_FUT_OPTIONCODE>())
  .def_property_readonly("bExchangeID", [](const OK_FUT_OPTIONCODE& self) {return self.ExchangeID;})
  .def_property_readonly("bInstrumentID", [](const OK_FUT_OPTIONCODE& self) {return self.InstrumentID;})
  .def_property_readonly("bInstrumentName", [](const OK_FUT_OPTIONCODE& self) {return self.InstrumentName;})
  .def_property_readonly("bProductID", [](const OK_FUT_OPTIONCODE& self) {return self.ProductID;})
  .def_readonly("ProductClass", &OK_FUT_OPTIONCODE::ProductClass)
  .def_readonly("VolumeMultiple", &OK_FUT_OPTIONCODE::VolumeMultiple)
  .def_readonly("PriceTick", &OK_FUT_OPTIONCODE::PriceTick)
  .def_readonly("OpenDate", &OK_FUT_OPTIONCODE::OpenDate)
  .def_readonly("ExpireDate", &OK_FUT_OPTIONCODE::ExpireDate)
  .def_readonly("IsTrading", &OK_FUT_OPTIONCODE::IsTrading)
  .def_property_readonly("bUnderlyingInstrID", [](const OK_FUT_OPTIONCODE& self) {return self.UnderlyingInstrID;})
  .def_readonly("CPType", &OK_FUT_OPTIONCODE::CPType)
  .def_readonly("strikeModeType", &OK_FUT_OPTIONCODE::strikeModeType)
  .def_readonly("StrikePrice", &OK_FUT_OPTIONCODE::StrikePrice)
  .def_readonly("UnderlyingMultiple", &OK_FUT_OPTIONCODE::UnderlyingMultiple)
  .def_readonly("blkType", &OK_FUT_OPTIONCODE::blkType)
;
py::class_<OK_MARKET_DATA_BASE>(m, "OK_MARKET_DATA_BASE")
  .def(py::init<>())
  .def(py::init<OK_MARKET_DATA_BASE>())
  .def_property_readonly("bszWindCode", [](const OK_MARKET_DATA_BASE& self) {return self.szWindCode;})
  .def_readonly("nActionDay", &OK_MARKET_DATA_BASE::nActionDay)
  .def_readonly("nTime", &OK_MARKET_DATA_BASE::nTime)
  .def_readonly("nPreClose", &OK_MARKET_DATA_BASE::nPreClose)
  .def_readonly("nOpen", &OK_MARKET_DATA_BASE::nOpen)
  .def_readonly("nHigh", &OK_MARKET_DATA_BASE::nHigh)
  .def_readonly("nLow", &OK_MARKET_DATA_BASE::nLow)
  .def_readonly("nMatch", &OK_MARKET_DATA_BASE::nMatch)
  .def_readonly("nNumTrades", &OK_MARKET_DATA_BASE::nNumTrades)
  .def_readonly("iVolume", &OK_MARKET_DATA_BASE::iVolume)
  .def_readonly("iTurnover", &OK_MARKET_DATA_BASE::iTurnover)
  .def_readonly("nIOPV", &OK_MARKET_DATA_BASE::nIOPV)
  .def_readonly("nYieldToMaturity", &OK_MARKET_DATA_BASE::nYieldToMaturity)
  .def_readonly("nHighLimited", &OK_MARKET_DATA_BASE::nHighLimited)
  .def_readonly("nLowLimited", &OK_MARKET_DATA_BASE::nLowLimited)
;
py::class_<OK_MARKET_DATA_L1>(m, "OK_MARKET_DATA_L1")
  .def(py::init<>())
  .def(py::init<OK_MARKET_DATA_L1>())
  .def_readonly("b", &OK_MARKET_DATA_L1::b)
  .def_readonly("nAskPrice", &OK_MARKET_DATA_L1::nAskPrice)
  .def_readonly("nAskVol", &OK_MARKET_DATA_L1::nAskVol)
  .def_readonly("nBidPrice", &OK_MARKET_DATA_L1::nBidPrice)
  .def_readonly("nBidVol", &OK_MARKET_DATA_L1::nBidVol)
;
py::class_<OK_MARKET_DATA_L2>(m, "OK_MARKET_DATA_L2")
  .def(py::init<>())
  .def(py::init<OK_MARKET_DATA_L2>())
  .def_readonly("b", &OK_MARKET_DATA_L2::b)
  .def_readonly("nAskPrice", &OK_MARKET_DATA_L2::nAskPrice)
  .def_readonly("nAskVol", &OK_MARKET_DATA_L2::nAskVol)
  .def_readonly("nBidPrice", &OK_MARKET_DATA_L2::nBidPrice)
  .def_readonly("nBidVol", &OK_MARKET_DATA_L2::nBidVol)
  .def_readonly("nTotalBidVol", &OK_MARKET_DATA_L2::nTotalBidVol)
  .def_readonly("nTotalAskVol", &OK_MARKET_DATA_L2::nTotalAskVol)
  .def_readonly("nWeightedAvgBidPrice", &OK_MARKET_DATA_L2::nWeightedAvgBidPrice)
  .def_readonly("nWeightedAvgAskPrice", &OK_MARKET_DATA_L2::nWeightedAvgAskPrice)
;
py::class_<OK_INDEX_DATA>(m, "OK_INDEX_DATA")
  .def(py::init<>())
  .def(py::init<OK_INDEX_DATA>())
  .def_property_readonly("bszWindCode", [](const OK_INDEX_DATA& self) {return self.szWindCode;})
  .def_readonly("nActionDay", &OK_INDEX_DATA::nActionDay)
  .def_readonly("nTime", &OK_INDEX_DATA::nTime)
  .def_readonly("nPreClose", &OK_INDEX_DATA::nPreClose)
  .def_readonly("nOpen", &OK_INDEX_DATA::nOpen)
  .def_readonly("nHigh", &OK_INDEX_DATA::nHigh)
  .def_readonly("nLow", &OK_INDEX_DATA::nLow)
  .def_readonly("nMatch", &OK_INDEX_DATA::nMatch)
  .def_readonly("iVolume", &OK_INDEX_DATA::iVolume)
  .def_readonly("iTurnover", &OK_INDEX_DATA::iTurnover)
  .def_property_readonly("bexchange", [](const OK_INDEX_DATA& self) {return self.exchange;})
  .def_property_readonly("bcurrency", [](const OK_INDEX_DATA& self) {return self.currency;})
;
py::class_<OK_FUTURE_DATA_BASE>(m, "OK_FUTURE_DATA_BASE")
  .def(py::init<>())
  .def(py::init<OK_FUTURE_DATA_BASE>())
  .def_property_readonly("bszWindCode", [](const OK_FUTURE_DATA_BASE& self) {return self.szWindCode;})
  .def_readonly("nActionDay", &OK_FUTURE_DATA_BASE::nActionDay)
  .def_readonly("nTradingDay", &OK_FUTURE_DATA_BASE::nTradingDay)
  .def_readonly("nTime", &OK_FUTURE_DATA_BASE::nTime)
  .def_readonly("iPreOpenInterest", &OK_FUTURE_DATA_BASE::iPreOpenInterest)
  .def_readonly("nPreClose", &OK_FUTURE_DATA_BASE::nPreClose)
  .def_readonly("nPreSettlePrice", &OK_FUTURE_DATA_BASE::nPreSettlePrice)
  .def_readonly("nOpen", &OK_FUTURE_DATA_BASE::nOpen)
  .def_readonly("nHigh", &OK_FUTURE_DATA_BASE::nHigh)
  .def_readonly("nLow", &OK_FUTURE_DATA_BASE::nLow)
  .def_readonly("nMatch", &OK_FUTURE_DATA_BASE::nMatch)
  .def_readonly("iVolume", &OK_FUTURE_DATA_BASE::iVolume)
  .def_readonly("iTurnover", &OK_FUTURE_DATA_BASE::iTurnover)
  .def_readonly("iOpenInterest", &OK_FUTURE_DATA_BASE::iOpenInterest)
  .def_readonly("nClose", &OK_FUTURE_DATA_BASE::nClose)
  .def_readonly("nSettlePrice", &OK_FUTURE_DATA_BASE::nSettlePrice)
  .def_readonly("nHighLimited", &OK_FUTURE_DATA_BASE::nHighLimited)
  .def_readonly("nLowLimited", &OK_FUTURE_DATA_BASE::nLowLimited)
  .def_readonly("nPreDelta", &OK_FUTURE_DATA_BASE::nPreDelta)
  .def_readonly("nCurrDelta", &OK_FUTURE_DATA_BASE::nCurrDelta)
  .def_readonly("nAvgPrice", &OK_FUTURE_DATA_BASE::nAvgPrice)
;
py::class_<OK_FUTURE_DATA_L1>(m, "OK_FUTURE_DATA_L1")
  .def(py::init<>())
  .def(py::init<OK_FUTURE_DATA_L1>())
  .def_readonly("b", &OK_FUTURE_DATA_L1::b)
  .def_readonly("nAskPrice", &OK_FUTURE_DATA_L1::nAskPrice)
  .def_readonly("nAskVol", &OK_FUTURE_DATA_L1::nAskVol)
  .def_readonly("nBidPrice", &OK_FUTURE_DATA_L1::nBidPrice)
  .def_readonly("nBidVol", &OK_FUTURE_DATA_L1::nBidVol)
;
py::class_<OK_FUTURE_DATA_L2>(m, "OK_FUTURE_DATA_L2")
  .def(py::init<>())
  .def(py::init<OK_FUTURE_DATA_L2>())
  .def_readonly("b", &OK_FUTURE_DATA_L2::b)
  .def_readonly("nAskPrice", &OK_FUTURE_DATA_L2::nAskPrice)
  .def_readonly("nAskVol", &OK_FUTURE_DATA_L2::nAskVol)
  .def_readonly("nBidPrice", &OK_FUTURE_DATA_L2::nBidPrice)
  .def_readonly("nBidVol", &OK_FUTURE_DATA_L2::nBidVol)
;
py::class_<OK_TRANSACTION>(m, "OK_TRANSACTION")
  .def(py::init<>())
  .def(py::init<OK_TRANSACTION>())
  .def_property_readonly("bszWindCode", [](const OK_TRANSACTION& self) {return self.szWindCode;})
  .def_readonly("nActionDay", &OK_TRANSACTION::nActionDay)
  .def_readonly("nTime", &OK_TRANSACTION::nTime)
  .def_readonly("nIndex", &OK_TRANSACTION::nIndex)
  .def_readonly("nPrice", &OK_TRANSACTION::nPrice)
  .def_readonly("nVolume", &OK_TRANSACTION::nVolume)
  .def_readonly("nBSFlag", &OK_TRANSACTION::nBSFlag)
  .def_readonly("chOrderKind", &OK_TRANSACTION::chOrderKind)
  .def_readonly("chFunctionCode", &OK_TRANSACTION::chFunctionCode)
  .def_readonly("nAskOrder", &OK_TRANSACTION::nAskOrder)
  .def_readonly("nBidOrder", &OK_TRANSACTION::nBidOrder)
;
py::class_<OK_ORDER>(m, "OK_ORDER")
  .def(py::init<>())
  .def(py::init<OK_ORDER>())
  .def_property_readonly("bszWindCode", [](const OK_ORDER& self) {return self.szWindCode;})
  .def_readonly("nActionDay", &OK_ORDER::nActionDay)
  .def_readonly("nTime", &OK_ORDER::nTime)
  .def_readonly("nOrder", &OK_ORDER::nOrder)
  .def_readonly("nPrice", &OK_ORDER::nPrice)
  .def_readonly("nVolume", &OK_ORDER::nVolume)
  .def_readonly("chOrderKind", &OK_ORDER::chOrderKind)
  .def_readonly("chFunctionCode", &OK_ORDER::chFunctionCode)
;
py::class_<OK_ORDER_QUEUE>(m, "OK_ORDER_QUEUE")
  .def(py::init<>())
  .def(py::init<OK_ORDER_QUEUE>())
  .def_property_readonly("bszWindCode", [](const OK_ORDER_QUEUE& self) {return self.szWindCode;})
  .def_readonly("nActionDay", &OK_ORDER_QUEUE::nActionDay)
  .def_readonly("nTime", &OK_ORDER_QUEUE::nTime)
  .def_readonly("nSide", &OK_ORDER_QUEUE::nSide)
  .def_readonly("nPrice", &OK_ORDER_QUEUE::nPrice)
  .def_readonly("nOrders", &OK_ORDER_QUEUE::nOrders)
  .def_readonly("nABItems", &OK_ORDER_QUEUE::nABItems)
  .def_readonly("nABVolume", &OK_ORDER_QUEUE::nABVolume)
;
py::class_<OK_Sec_MinK>(m, "OK_Sec_MinK")
  .def(py::init<>())
  .def(py::init<OK_Sec_MinK>())
  .def_property_readonly("bszWindCode", [](const OK_Sec_MinK& self) {return self.szWindCode;})
  .def_readonly("nActionDay", &OK_Sec_MinK::nActionDay)
  .def_readonly("nTime", &OK_Sec_MinK::nTime)
  .def_readonly("nPreClose", &OK_Sec_MinK::nPreClose)
  .def_readonly("nOpen", &OK_Sec_MinK::nOpen)
  .def_readonly("nHigh", &OK_Sec_MinK::nHigh)
  .def_readonly("nLow", &OK_Sec_MinK::nLow)
  .def_readonly("nMatch", &OK_Sec_MinK::nMatch)
  .def_readonly("iVolume", &OK_Sec_MinK::iVolume)
  .def_readonly("iTurnover", &OK_Sec_MinK::iTurnover)
  .def_readonly("nNumTrades", &OK_Sec_MinK::nNumTrades)
;
py::class_<OK_OptFut_MinK>(m, "OK_OptFut_MinK")
  .def(py::init<>())
  .def(py::init<OK_OptFut_MinK>())
  .def_property_readonly("bszWindCode", [](const OK_OptFut_MinK& self) {return self.szWindCode;})
  .def_readonly("nTradingDay", &OK_OptFut_MinK::nTradingDay)
  .def_readonly("nActionDay", &OK_OptFut_MinK::nActionDay)
  .def_readonly("nTime", &OK_OptFut_MinK::nTime)
  .def_readonly("nPreClose", &OK_OptFut_MinK::nPreClose)
  .def_readonly("nOpen", &OK_OptFut_MinK::nOpen)
  .def_readonly("nHigh", &OK_OptFut_MinK::nHigh)
  .def_readonly("nLow", &OK_OptFut_MinK::nLow)
  .def_readonly("nMatch", &OK_OptFut_MinK::nMatch)
  .def_readonly("iVolume", &OK_OptFut_MinK::iVolume)
  .def_readonly("iTurnover", &OK_OptFut_MinK::iTurnover)
  .def_readonly("iOpenInterest", &OK_OptFut_MinK::iOpenInterest)
;
py::class_<OK_Sec_DayK>(m, "OK_Sec_DayK")
  .def(py::init<>())
  .def(py::init<OK_Sec_DayK>())
  .def_property_readonly("bszWindCode", [](const OK_Sec_DayK& self) {return self.szWindCode;})
  .def_readonly("nTradingDay", &OK_Sec_DayK::nTradingDay)
  .def_readonly("nPreClose", &OK_Sec_DayK::nPreClose)
  .def_readonly("nOpen", &OK_Sec_DayK::nOpen)
  .def_readonly("nHigh", &OK_Sec_DayK::nHigh)
  .def_readonly("nLow", &OK_Sec_DayK::nLow)
  .def_readonly("nMatch", &OK_Sec_DayK::nMatch)
  .def_readonly("iVolume", &OK_Sec_DayK::iVolume)
  .def_readonly("iTurnover", &OK_Sec_DayK::iTurnover)
  .def_readonly("nNumTrades", &OK_Sec_DayK::nNumTrades)
;
py::class_<OK_OptFut_DayK>(m, "OK_OptFut_DayK")
  .def(py::init<>())
  .def(py::init<OK_OptFut_DayK>())
  .def_property_readonly("bszWindCode", [](const OK_OptFut_DayK& self) {return self.szWindCode;})
  .def_readonly("nTradingDay", &OK_OptFut_DayK::nTradingDay)
  .def_readonly("iPreOpenInterest", &OK_OptFut_DayK::iPreOpenInterest)
  .def_readonly("nPreClose", &OK_OptFut_DayK::nPreClose)
  .def_readonly("nPreSettlePrice", &OK_OptFut_DayK::nPreSettlePrice)
  .def_readonly("nOpen", &OK_OptFut_DayK::nOpen)
  .def_readonly("nHigh", &OK_OptFut_DayK::nHigh)
  .def_readonly("nLow", &OK_OptFut_DayK::nLow)
  .def_readonly("nMatch", &OK_OptFut_DayK::nMatch)
  .def_readonly("iVolume", &OK_OptFut_DayK::iVolume)
  .def_readonly("iTurnover", &OK_OptFut_DayK::iTurnover)
  .def_readonly("iOpenInterest", &OK_OptFut_DayK::iOpenInterest)
  .def_readonly("nSettlePrice", &OK_OptFut_DayK::nSettlePrice)
;
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