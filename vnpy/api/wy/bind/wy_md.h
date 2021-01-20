#ifndef PLAN21_WY_MD_H_
#define PLAN21_WY_MD_H_
#pragma once

#include <quote/wyquote_struct.h>
#ifndef ZY_C_SHARP
#define ZY_C_SHARP
#include <WyDCFdt/WyDCFdt.h>
#undef ZY_C_SHARP
#endif

#include <memory>
#include <tuple>
#include <vector>

class WyMdPimpl;
/*bool push_snapshot, bool push_transaction, bool push_order, bool push_orderque, bool push_k,
std::string blks, std::string inss
*/
using SubscribeInfoTuple = std::tuple<bool, bool, bool, bool, bool, std::string, std::string>;

class WyMd: public IWyQuoteCB
{
public:
    WyMd();
	~WyMd();
    void connect(const std::string& ip, int port);
    void subscribe(const SubscribeInfoTuple& subscribe_info);
	void unsubscribe();
    SubscribeInfoTuple get_subscribe_info();

	void OnCodeList(int sec_cnt, const OK_CODE* sec_codes,
		int secopt_cnt, const OK_OPTIONCODE* secopt_codes,
		int fut_cnt, const OK_FUT_CODE* fut_codes,
		int futopt_cnt, const OK_FUT_OPTIONCODE* futopt_codes,
		int trading_day) override final;
    // Redeclare all interfaces as pure virtual
    virtual void OnConnect(int reason) = 0;

	virtual void OnCodeListVector(const std::vector<OK_CODE>&, const std::vector<OK_OPTIONCODE>&, 
		const std::vector<OK_FUT_CODE>&, const std::vector<OK_FUT_OPTIONCODE>&,
		int trading_day) = 0;
    virtual void OnIndRealData(const OK_INDEX_DATA &q) = 0;
	virtual void OnSecRealDataL1(const OK_MARKET_DATA_L1 &q) = 0;
	virtual void OnSecRealDataL2(const OK_MARKET_DATA_L2 &q) = 0;
	virtual void OnFutRealDataL1(const OK_FUTURE_DATA_L1 &q) = 0;
	virtual void OnFutRealDataL2(const OK_FUTURE_DATA_L2 &q) = 0;
	virtual void OnSecTransaction(const OK_TRANSACTION &q) = 0;
	virtual void OnSecOrder(const OK_ORDER &q) = 0;
	virtual void OnSecOrderQueue(const OK_ORDER_QUEUE &q) = 0;
	virtual void OnSecMinK(int cnt, const OK_Sec_MinK &ks) = 0;
	virtual void OnOptFutMinK(int cnt, const OK_OptFut_MinK &ks) = 0;
    virtual void OnIndRealDataByShares(const OK_INDEX_DATA &q) = 0;
    virtual void OnIndRealDataByWeights(const OK_INDEX_DATA &q) = 0;

	virtual void OnServerQuoteDisconnected() = 0;
	virtual void OnServerQuoteReconnected() = 0;

private:
    std::unique_ptr<WyMdPimpl> pimpl_;
};
#endif // PLAN21_WY_MD_H_