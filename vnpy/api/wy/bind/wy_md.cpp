#include "wy_md.h"
#include <iostream>
struct WyMdPimpl {
    CWyDCFdt ctrl_;
    std::string blk_, ins_;
};

WyMd::WyMd():
pimpl_(std::make_unique<WyMdPimpl>())
{}

WyMd::~WyMd()
{
}

void WyMd::connect(const std::string& ip, int port)
{
    std::cout << ip << ":" << port << std::endl;
    pimpl_->ctrl_.SetQuoteSvrIP(ip.c_str(), static_cast<unsigned int>(port), this);
    pimpl_->ctrl_.Connect();
}

void WyMd::subscribe(const SubscribeInfoTuple& subscribe_info)
{
    std::cout << "subscribe" << std::endl;
    bool sub = true;
    bool push_snapshot, push_transaction, push_order, push_orderque, push_k;
    std::tie(push_snapshot, push_transaction, push_order, push_orderque, push_k, pimpl_->blk_, pimpl_->ins_)
     = subscribe_info;
    std::cout << pimpl_->blk_ << std::endl;
    pimpl_->ctrl_.Subscribe(sub, push_snapshot, push_transaction, push_order, push_orderque, push_k,
        pimpl_->blk_.empty() ? NULL : pimpl_->blk_.c_str(), pimpl_->ins_.empty() ? NULL : pimpl_->ins_.c_str());
    std::cout << "end of call" << std::endl;
}

void WyMd::unsubscribe()
{
    bool sub = false, push_snapshot = false, push_transaction = false, push_order = false, push_orderque = false, push_k = false;
    std::string blks{}, inss{};
    pimpl_->ctrl_.Subscribe(sub, push_snapshot, push_transaction, push_order, push_orderque, push_k,
        blks.c_str(), inss.c_str());
}

SubscribeInfoTuple WyMd::get_subscribe_info()
{
    bool push_snapshot, push_transaction, push_order, push_orderque, push_k;
	std::string blks, inss;
    pimpl_->ctrl_.GetSubscribeInfo(push_snapshot, push_transaction, push_order, push_orderque, push_k,
    blks, inss);

    return std::make_tuple(push_snapshot, push_transaction, push_order, push_orderque, push_k, blks, inss);
}

void WyMd::OnCodeList(int sec_cnt, const OK_CODE* sec_codes, int secopt_cnt, const OK_OPTIONCODE* secopt_codes, int fut_cnt, const OK_FUT_CODE* fut_codes, int futopt_cnt, const OK_FUT_OPTIONCODE* futopt_codes, int trading_day)
{
    std::cout << "OnCodeList" << std::endl;
    std::vector<OK_CODE> seccodes_vec{};
    seccodes_vec.assign(sec_codes, sec_codes + sec_cnt);
    std::vector<OK_OPTIONCODE> secoptcodes_vec{};
    secoptcodes_vec.assign(secopt_codes, secopt_codes + secopt_cnt);
    std::vector<OK_FUT_CODE> futcodes_vec{};
    futcodes_vec.assign(fut_codes, fut_codes + fut_cnt);
    std::vector<OK_FUT_OPTIONCODE> futoptcodes_vec{};
    futoptcodes_vec.assign(futopt_codes, futopt_codes + futopt_cnt);

    OnCodeListVector(seccodes_vec, secoptcodes_vec, futcodes_vec, futoptcodes_vec, trading_day);
}
