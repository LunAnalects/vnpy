#ifndef PLAN21_PY_WY_MD_H_
#define PLAN21_PY_WY_MD_H_
#pragma once

#include "wy_md.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>

namespace py = pybind11;

class PyWyMd: public WyMd
{
public:
    using WyMd::WyMd;

    // Pybinding to WyMd
    void OnConnect(int reason) override {
        py::gil_scoped_acquire acquire;
        py::print("OnConnect");
        PYBIND11_OVERRIDE_PURE(
            void,
            WyMd, 
            OnConnect, 
            reason 
        );
    }

    void OnCodeListVector(const std::vector<OK_CODE>& sec_codes, const std::vector<OK_OPTIONCODE>& secopt_codes,
        const std::vector<OK_FUT_CODE>& fut_codes, const std::vector<OK_FUT_OPTIONCODE>& futopt_codes,
		int trading_day) override {
        py::gil_scoped_acquire acquire;
        py::print("OnCodeListVector");
        PYBIND11_OVERRIDE_PURE(
            void,
            WyMd, 
            OnCodeListVector,
            sec_codes,
            secopt_codes,
            fut_codes,
            futopt_codes,
            trading_day
        );
    }

    void OnIndRealData(const OK_INDEX_DATA &q) override {
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnIndRealData,       
            q         
        );
    }

	void OnSecRealDataL1(const OK_MARKET_DATA_L1 &q) override {
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnSecRealDataL1,       
            q         
        );
    }

	void OnSecRealDataL2(const OK_MARKET_DATA_L2 &q) override {
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnSecRealDataL2,       
            q         
        );
    }

	void OnFutRealDataL1(const OK_FUTURE_DATA_L1 &q) override {
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnFutRealDataL1,       
            q         
        );
    }
	void OnFutRealDataL2(const OK_FUTURE_DATA_L2 &q) override {
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnFutRealDataL2,       
            q         
        );
    }
	void OnSecTransaction(const OK_TRANSACTION &q) override {
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnSecTransaction,       
            q         
        );
    };
	void OnSecOrder(const OK_ORDER &q) override {
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnSecOrder,       
            q         
        );
    };
	void OnSecOrderQueue(const OK_ORDER_QUEUE &q) override {
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnSecOrderQueue,       
            q         
        );
    };

	void OnSecMinK(int cnt, const OK_Sec_MinK &ks) override {
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnSecMinK,
            cnt,       
            ks         
        );
    };

	void OnOptFutMinK(int cnt, const OK_OptFut_MinK &ks) override {
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnSecMinK,
            cnt,       
            ks       
        );
    };

    void OnIndRealDataByShares(const OK_INDEX_DATA &q) override {
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnIndRealDataByShares,       
            q         
        );
    }

    void OnIndRealDataByWeights(const OK_INDEX_DATA &q) override {
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnIndRealDataByWeights,       
            q         
        );
    }


	void OnServerQuoteDisconnected() override {
        py::gil_scoped_acquire acquire;
        py::print("OnServerQuoteDisconnected");
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnServerQuoteDisconnected  
        );
    };

	void OnServerQuoteReconnected() override{
        py::gil_scoped_acquire acquire;
        py::print("OnServerQuoteReconnected");
        PYBIND11_OVERRIDE_PURE(
            void, 
            WyMd,
            OnServerQuoteReconnected  
        );
    };

};

#endif // PLAN21_PY_WY_MD_H_