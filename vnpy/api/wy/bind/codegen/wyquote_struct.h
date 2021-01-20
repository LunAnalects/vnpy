#pragma once
#include <memory.h>
#include "quote_defs.h"

#pragma  pack(push)
#pragma pack(1)

//板块定义:
enum
{
	OK_BLK_Unknown			= 0,	//未知板块

	OK_BLK_Index_SH			= 1,	//上证指数
	OK_BLK_Index_SZ			= 2,	//深证指数

	OK_BLK_Stk_SHA			= 100,	//上证A股
	OK_BLK_Stk_SZA			= 101,	//深证A股
	OK_BLK_Stk_S			= 102,	//中小板
	OK_BLK_Stk_G			= 103,	//创业板
	OK_BLK_Stk_SHB			= 104,	//上证B股
	OK_BLK_Stk_SZB			= 105,	//深证B股
	OK_BLK_Stk_SHFJ			= 106,	//上证分级基金AB股
	OK_BLK_Stk_SZFJ			= 107,	//深证分级基金AB股
    OK_BLK_Stk_SCI          = 108,  //科创板
	OK_BLK_Stk_ST			= 199,	//ST股票

	OK_BLK_Fund_LOF			= 200,	//上市开放基金LOF
	OK_BLK_Fund_ETF			= 201,	//交易型开放式指数基金ETF

	OK_BLK_Repo_NA			= 400,	//国债回购

	OK_BLK_Fut_CFFEX_Index	= 600,	//中金所指数期货
	OK_BLK_Fut_CFFEX_T		= 601,	//中金所国债期货
	OK_BLK_Fut_DCE			= 620,	//大商所商品期货
	OK_BLK_Fut_CZCE			= 640,	//郑商所商品期货
	OK_BLK_Fut_SHFE			= 660,	//上期所商品期货
	OK_BLK_Fut_INE			= 680,	//能源所商品期货

	OK_BLK_Option_ETF50		= 700,	//ETF50期权

	OK_BLK_CUSTOM           = 1000
};
//////////////////////////////////////////////////////////////////////////
//证券码表
struct OK_CODE
{
	char InstrumentID[32];    //唯一代码: 600000.SH;000001.SZ
	char InstrumentName[32]; //gb2312编码
	int blkType;	//所属的板块，上面enum里面的值
	OK_CODE()
	{
		memset(this, 0, sizeof(OK_CODE));
	}
	OK_CODE(const OK_CODE &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_CODE& operator=(const OK_CODE& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//证券期权码表
struct OK_OPTIONCODE
{
	char InstrumentID[32];    //唯一代码: 600000.SH;000001.SZ
	char InstrumentName[32]; //gb2312编码
	int blkType;	//所属的板块，上面enum里面的值
    char ExchangeID[8];
	char UnderlyingInstrID[32];//// 标的证券代码:510050.SH
	CtOptCPType CPType;
	CtOptStrikeModeType strikeModeType;
    double PriceTick;///最小变动价位
	double  StrikePrice;// 期权行权价，右对齐，精确到厘
	int  VolumeMultiple;// 合约单位
	int  OpenDate;      // 期权首个交易日,YYYYMMDD
	int  ExpireDate;    // 期权最后交易日，YYYYMMDD
	OK_OPTIONCODE()
	{
		memset(this, 0, sizeof(OK_OPTIONCODE));
		CPType = Ct_OCT_no;
		strikeModeType = Ct_OCT_STM_NotSupport;
	}
	OK_OPTIONCODE(const OK_OPTIONCODE &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_OPTIONCODE& operator=(const OK_OPTIONCODE& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//期货码表
struct OK_FUT_CODE
{
	char ExchangeID[EXCHANGE_ID_LEN];///交易所代码
	char InstrumentID[INSTRUMENT_ID_LEN];///合约代码
	char InstrumentName[INSTRUMENTNAME_LEN];///合约名称
	char ProductID[INSTRUMENT_ID_LEN];///产品代码,如IF
	CtProductClass ProductClass;///产品类型
	int	VolumeMultiple;///合约数量乘数
	double PriceTick;///最小变动价位
	int	OpenDate;///上市日:20160215
	int	ExpireDate;///到期日:20160215
	bool IsTrading;///当前是否交易
	CtCombtType CombinationType;///组合类型

	int blkType;	//所属的板块，上面enum里面的值
	OK_FUT_CODE()
	{
		memset(this, 0, sizeof(OK_FUT_CODE));
		ProductClass = Ct_PC_NotSupport;
		CombinationType = Ct_COMBT_NotSupport;
	}
	OK_FUT_CODE(const OK_FUT_CODE &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_FUT_CODE& operator=(const OK_FUT_CODE& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//期货期权码表
struct OK_FUT_OPTIONCODE
{
	char ExchangeID[EXCHANGE_ID_LEN];///交易所代码
	char InstrumentID[INSTRUMENT_ID_LEN];///合约代码
	char InstrumentName[INSTRUMENTNAME_LEN];///合约名称
	char ProductID[INSTRUMENT_ID_LEN];///产品代码,如IF
	CtProductClass ProductClass;///产品类型
	int	VolumeMultiple;///合约数量乘数
	double PriceTick;///最小变动价位
	int	OpenDate;///上市日:20160215
	int	ExpireDate;///到期日:20160215
	bool IsTrading;///当前是否交易

	char UnderlyingInstrID[INSTRUMENT_ID_LEN];///基础商品代码
	CtOptCPType CPType;///期权类型
	CtOptStrikeModeType strikeModeType;
	double StrikePrice;///执行价
	double UnderlyingMultiple;///合约基础商品乘数

	int blkType;	//所属的板块，上面enum里面的值

	OK_FUT_OPTIONCODE()
	{
		memset(this, 0, sizeof(OK_FUT_OPTIONCODE));
		ProductClass = Ct_PC_NotSupport;
		CPType = Ct_OCT_no;
		strikeModeType = Ct_OCT_STM_NotSupport;
	}
	OK_FUT_OPTIONCODE(const OK_FUT_OPTIONCODE &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_FUT_OPTIONCODE& operator=(const OK_FUT_OPTIONCODE& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};
//////////////////////////////////////////////////////////////////////////
//证券行情基本数据
struct OK_MARKET_DATA_BASE
{
	char			szWindCode[32];         //600001.SH;000001.SZ
	int				nActionDay;             //业务发生日(自然日)
	int				nTime;					//时间(HHMMSSmmm)
	double			nPreClose;				//前收盘价
	double			nOpen;					//开盘价
	double			nHigh;					//最高价
	double			nLow;					//最低价
	double			nMatch;					//最新价
	unsigned int	nNumTrades;				//成交笔数
	__int64			iVolume;				//成交总量
	__int64			iTurnover;				//成交总金额
	double			nIOPV;					//IOPV净值估值
	double			nYieldToMaturity;		//到期收益率
	double			nHighLimited;			//涨停价
	double			nLowLimited;			//跌停价

	//20151015添加国外市场数据扩展
	//char			exchange[9];			//交易所
	//char			currency[9];			//币种
	OK_MARKET_DATA_BASE()
	{
		memset(this, 0, sizeof(OK_MARKET_DATA_BASE));
	}
	OK_MARKET_DATA_BASE(const OK_MARKET_DATA_BASE &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_MARKET_DATA_BASE& operator=(const OK_MARKET_DATA_BASE& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//level 1证券行情
struct OK_MARKET_DATA_L1
{
	OK_MARKET_DATA_BASE b;
	double			nAskPrice[5];			//申卖价
	unsigned int	nAskVol[5];				//申卖量
	double			nBidPrice[5];			//申买价
	unsigned int	nBidVol[5];				//申买量
	OK_MARKET_DATA_L1()
	{
		memset(this, 0, sizeof(OK_MARKET_DATA_L1));
	}
	OK_MARKET_DATA_L1(const OK_MARKET_DATA_L1 &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_MARKET_DATA_L1& operator=(const OK_MARKET_DATA_L1& rhs)
	{
		if(this == &rhs)
			return *this;

		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//level 2证券行情
struct OK_MARKET_DATA_L2
{
	OK_MARKET_DATA_BASE b;
	double			nAskPrice[10];			//申卖价
	unsigned int	nAskVol[10];			//申卖量
	double			nBidPrice[10];			//申买价
	unsigned int	nBidVol[10];			//申买量
	__int64			nTotalBidVol;			//委托买入总量
	__int64			nTotalAskVol;			//委托卖出总量
	double			nWeightedAvgBidPrice;	//加权平均委买价格
	double			nWeightedAvgAskPrice;	//加权平均委卖价格

	OK_MARKET_DATA_L2()
	{
		memset(this, 0, sizeof(OK_MARKET_DATA_L2));
	}
	OK_MARKET_DATA_L2(const OK_MARKET_DATA_L2 &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_MARKET_DATA_L2& operator=(const OK_MARKET_DATA_L2& rhs)
	{
		if(this == &rhs)
			return *this;

		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//指数行情
struct OK_INDEX_DATA
{
	char        szWindCode[32];         //399300.SZ;000001.SH 
	int         nActionDay;             //业务发生日(自然日)
	int         nTime;			        //时间(HHMMSSmmm)
	double	    nPreClose;	        //前盘指数
	double		nOpen;					//开盘价
	double		nHigh;					//最高价
	double		nLow;					//最低价
	double		nMatch;					//最新价
	__int64	    iVolume;	        //参与计算相应指数的交易数量
	__int64	    iTurnover;		        //参与计算相应指数的成交金额

	//20151015添加国外市场数据扩展
	char			exchange[9];			//交易所
	char			currency[9];			//币种
	OK_INDEX_DATA()
	{
		memset(this, 0, sizeof(OK_INDEX_DATA));
	}
	OK_INDEX_DATA(const OK_INDEX_DATA &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_INDEX_DATA& operator=(const OK_INDEX_DATA& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//期货/期权行情基本数据
struct OK_FUTURE_DATA_BASE
{
	char			szWindCode[32];         //SR709C5700;IF1703;rb1710;m1712-P-2600
	int				nActionDay;             //业务发生日(自然日)
	int				nTradingDay;            //交易日
	int				nTime;					//时间(HHMMSSmmm)	
	__int64			iPreOpenInterest;		//昨持仓
	double			nPreClose;				//昨收盘价
	double			nPreSettlePrice;		//昨结算
	double			nOpen;					//开盘价	
	double			nHigh;					//最高价
	double			nLow;					//最低价
	double			nMatch;					//最新价
	__int64			iVolume;				//成交总量
	__int64			iTurnover;				//成交总金额
	__int64			iOpenInterest;			//持仓总量
	double			nClose;					//今收盘
	double			nSettlePrice;			//今结算
	double			nHighLimited;			//涨停价
	double			nLowLimited;			//跌停价
	double			nPreDelta;			    //昨虚实度
	double			nCurrDelta;				//今虚实度
	double			nAvgPrice;				//均价

	//20151015添加国外市场数据扩展
	//char			exchange[9];			//交易所
	//char			currency[9];			//币种
	OK_FUTURE_DATA_BASE()
	{
		memset(this, 0, sizeof(OK_FUTURE_DATA_BASE));
	}
	OK_FUTURE_DATA_BASE(const OK_FUTURE_DATA_BASE &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_FUTURE_DATA_BASE& operator=(const OK_FUTURE_DATA_BASE& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//level 1期货/期权行情
struct OK_FUTURE_DATA_L1
{
	OK_FUTURE_DATA_BASE b;
	double			nAskPrice[1];			//申卖价
	unsigned int	nAskVol[1];				//申卖量
	double			nBidPrice[1];			//申买价
	unsigned int	nBidVol[1];				//申买量
	OK_FUTURE_DATA_L1()
	{
		memset(this, 0, sizeof(OK_FUTURE_DATA_L1));
	}
	OK_FUTURE_DATA_L1(const OK_FUTURE_DATA_L1 &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_FUTURE_DATA_L1& operator=(const OK_FUTURE_DATA_L1& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//level 2期货/期权行情
struct OK_FUTURE_DATA_L2
{
	OK_FUTURE_DATA_BASE b;
	double			nAskPrice[5];			//申卖价
	unsigned int	nAskVol[5];				//申卖量
	double			nBidPrice[5];			//申买价
	unsigned int	nBidVol[5];				//申买量

	OK_FUTURE_DATA_L2()
	{
		memset(this, 0, sizeof(OK_FUTURE_DATA_L2));
	}
	OK_FUTURE_DATA_L2(const OK_FUTURE_DATA_L2 &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_FUTURE_DATA_L2& operator=(const OK_FUTURE_DATA_L2& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//逐笔成交，对应《深圳证券交易所数据接口规范》中的回报库SJSHB.dbf一节HBYWLB（业务类别）字段取值范围如下：
//OrderKind FunctionCode    业务含义
//   '0'          '0'       交易业务成交记录
//   '0'          'C'       交易业务撤单回报记录
//   '2'          'C'       “即时成交剩余撤销委托”未能成交部分或其他原因的自动撤单回报记录
//   'K'          '0'       ETF基金申购/赎回成功回报记录或ETF基金赎回/赎回成功证券给付明细回报记录
//   'K'          'C'       ETF基金申购/赎回撤单回报记录
//   'V'          'C'       “最优五档即时成交剩余撤销委托”未能成交部分的自动撤单或其他原因的自动撤单回报记录
//   'W'          'C'       “全额成交或撤销委托”未能成交时的自动撤单或其他原因自动撤单回报记录
//   'X'          'C'       本方最优价格委托的撤单回报记录
//   'Y'          'C'       对手方最优价格委托的撤单回报记录
//   'Z'          '0'       ETF基金申购/赎回成功允许/必须现金替代明细回报记录
struct OK_TRANSACTION
{
	char    szWindCode[32];             //600001.SH;000001.SZ 
	int     nActionDay;                 //自然日
	int 	nTime;		                //成交时间(HHMMSSmmm)
	int 	nIndex;		                //成交编号
	double	nPrice;		                //成交价格
	int 	nVolume;	                //成交数量
	char    nBSFlag;                    //买卖方向(买：'B', 卖：'S', 其他:不明 ' '/ 'N')
	char    chOrderKind;                //成交类别
	char    chFunctionCode;             //成交代码
	int	    nAskOrder;	                //叫卖方委托序号
	int	    nBidOrder;	                //叫买方委托序号
	OK_TRANSACTION()
	{
		memset(this, 0, sizeof(OK_TRANSACTION));
	}
	OK_TRANSACTION(const OK_TRANSACTION &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_TRANSACTION& operator=(const OK_TRANSACTION& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//逐笔委托（深交所有，上交所没有）,以《深圳证券交易所数据接口规范》为参考含义如下：
//OrderKind FunctionCode 业务含义
//  '0'        'B'       正常交易业务的买委托记录
//  '0'        'S'       正常交易业务的卖委托记录
//  '0'        'C'       正常交易业务的撤单记录
//  '2'        'B'       即时成交剩余撤销买委托记录
//  '2'        'S'       即时成交剩余撤销卖委托记录
//  'K'        'B'       ETF基金申购申报记录
//  'K'        'S'       ETF基金赎回申报记录
//  'V'        'B'       最优五档即时成交剩余撤销买委托记录
//  'V'        'S'       最优五档即时成交剩余撤销卖委托记录
//  'W'        'B'       全额成交或撤销买委托记录
//  'W'        'S'       全额成交或撤销卖委托记录
//  'X'        'B'       本方最优价格买委托记录
//  'X'        'S'       本方最优价格卖委托记录
//  'X'        'C'       本方最优价格撤单委托记录
//  'Y'        'B'       对手方最优价格买委托记录
//  'Y'        'S'       对手方最优价格卖委托记录
//  'Y'        'C'       对手方最优价格撤单委托记录
struct OK_ORDER
{
	char    szWindCode[32]; //000001.SZ 
	int 	nActionDay;	    //委托日期(YYMMDD)
	int 	nTime;			//委托时间(HHMMSSmmm)
	int 	nOrder;	        //委托号
	double	nPrice;			//委托价格
	int 	nVolume;		//委托数量
	char    chOrderKind;	//委托类别
	char    chFunctionCode;	//委托代码('B','S','C')
	OK_ORDER()
	{
		memset(this, 0, sizeof(OK_ORDER));
	}
	OK_ORDER(const OK_ORDER &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_ORDER& operator=(const OK_ORDER& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//委托队列
struct OK_ORDER_QUEUE
{
	char    szWindCode[32]; //600001.SH 
	int     nActionDay;     //自然日
	int 	nTime;			//时间(HHMMSSmmm)
	char    nSide;			//买卖方向('B':Bid 'A':Ask)
	double	nPrice;			//委托价格
	int 	nOrders;		//订单数量
	int 	nABItems;		//明细个数
	int 	nABVolume[200];	//订单明细
	OK_ORDER_QUEUE()
	{
		memset(this, 0, sizeof(OK_ORDER_QUEUE));
	}
	OK_ORDER_QUEUE(const OK_ORDER_QUEUE &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_ORDER_QUEUE& operator=(const OK_ORDER_QUEUE& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

///////////////////////////////////历史K线///////////////////////////////////////
//证券分钟K线
struct OK_Sec_MinK
{
	char    szWindCode[32]; //600001.SH 
	int		nActionDay;             //业务发生日(自然日)
	int		nTime;			        //时间(HHMMSSmmm)
	double	nPreClose;	        //前一个K线价格
	double	nOpen;					//开盘价
	double	nHigh;					//最高价
	double	nLow;					//最低价
	double	nMatch;					//最新价
	__int64	iVolume;	        //参与计算相应指数的交易数量
	__int64	iTurnover;		        //参与计算相应指数的成交金额
	unsigned int	nNumTrades;				//成交笔数
	OK_Sec_MinK()
	{
		memset(this, 0, sizeof(OK_Sec_MinK));
	}
	OK_Sec_MinK(const OK_Sec_MinK &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_Sec_MinK& operator=(const OK_Sec_MinK& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//期权、期货分钟K线
struct OK_OptFut_MinK
{
	char			szWindCode[32];         //SR709C5700;IF1703;rb1710;m1712-P-2600
	int				nTradingDay;            //交易日
	int				nActionDay;             //业务发生日(自然日)
	int				nTime;					//时间(HHMMSSmmm)	
	double			nPreClose;				//前一个K线价格
	double			nOpen;					//开盘价	
	double			nHigh;					//最高价
	double			nLow;					//最低价
	double			nMatch;					//最新价
	__int64			iVolume;				//成交总量
	__int64			iTurnover;				//成交总金额
	__int64			iOpenInterest;			//持仓总量
	OK_OptFut_MinK()
	{
		memset(this, 0, sizeof(OK_OptFut_MinK));
	}
	OK_OptFut_MinK(const OK_OptFut_MinK &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_OptFut_MinK& operator=(const OK_OptFut_MinK& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//证券分钟K线
struct OK_Sec_DayK
{
	char    szWindCode[32]; //600001.SH 
	int		nTradingDay;             //交易日
	double	nPreClose;	        //前一个K线价格
	double	nOpen;					//开盘价
	double	nHigh;					//最高价
	double	nLow;					//最低价
	double	nMatch;					//最新价
	__int64	iVolume;	        //参与计算相应指数的交易数量
	__int64	iTurnover;		        //参与计算相应指数的成交金额
	unsigned int	nNumTrades;				//成交笔数
	OK_Sec_DayK()
	{
		memset(this, 0, sizeof(OK_Sec_DayK));
	}
	OK_Sec_DayK(const OK_Sec_DayK &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_Sec_DayK& operator=(const OK_Sec_DayK& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};

//期权、期货分钟K线
struct OK_OptFut_DayK
{
	char			szWindCode[32];         //SR709C5700;IF1703;rb1710;m1712-P-2600
	int				nTradingDay;            //交易日
	__int64			iPreOpenInterest;		//前一个K线持仓
	double			nPreClose;				//前一个K线收盘价
	double			nPreSettlePrice;		//前一个K线结算
	double			nOpen;					//开盘价	
	double			nHigh;					//最高价
	double			nLow;					//最低价
	double			nMatch;					//最新价
	__int64			iVolume;				//成交总量
	__int64			iTurnover;				//成交总金额
	__int64			iOpenInterest;			//持仓总量
	double			nSettlePrice;			//今结算
	OK_OptFut_DayK()
	{
		memset(this, 0, sizeof(OK_OptFut_DayK));
	}
	OK_OptFut_DayK(const OK_OptFut_DayK &rhs)
	{
		memcpy(this, &rhs, sizeof(rhs));
	}
	OK_OptFut_DayK& operator=(const OK_OptFut_DayK& rhs)
	{
		if(this == &rhs)
			return *this;
		memcpy(this, &rhs, sizeof(rhs));
		return *this;
	}
};
#pragma pack(pop)
