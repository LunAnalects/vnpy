#ifndef QUOTE_DEFS_H
#define QUOTE_DEFS_H

//用户代码长度
#define USERID_LEN 50
//用户密码长度
#define PASSWORD_LEN 50
//合约代码长度
#define INSTRUMENT_ID_LEN 31
//交易所id长度
#define EXCHANGE_ID_LEN 9
//合约名称长度
#define INSTRUMENTNAME_LEN 21
//成交编号长度
#define TRADEID_LEN 50
//状态信息长度
#define STATUSMSG_LEN 256
//错误信息长度
#define ERRMSG_LEN 1024
//真实柜台的委托编号长度
#define COUNTERENTRUSTNO_LEN 	60
//撤单需要的扩展数据长度
#define DELEXTRA_LEN 	60
//币种长度
#define CURRENCY_LEN 9
//预留长度
#define RESERVED_LEN 20
//策略错误信息长度
#define ST_ERRMSG_LEN 80

///证券类型
enum CtSecType
{
	Ct_ST_NotSupport	= '0',///未支持的类型
	Ct_ST_Stk			= 'S',///股票
	Ct_ST_Fut			= 'F',///期货
	Ct_ST_CommodityOpt	= 'O',///商品期货期权
	Ct_ST_ETFOpt		= 'E',///ETF期权
};

///期货合约所属产品类型
enum CtProductClass
{
	Ct_PC_NotSupport	= '0',///未支持的类型
	Ct_PC_Futures		= 'F',///期货		
	Ct_PC_Options		= 'O',///期货期权	
	Ct_PC_Combination	= 'C',///组合		
	Ct_PC_Spot			= '4',///即期		
	Ct_PC_EFP			= '5',///期转现		
	Ct_PC_SpotOption	= '6',///现货期权	
};


///期权认购认沽类型
enum CtOptCPType
{
	Ct_OCT_no   = '0',///未支持的类型
	Ct_OCT_Call = 'C',///看涨
	Ct_OCT_Put  = 'P',///看跌
};

///期权执行方式类型
enum CtOptStrikeModeType
{
	Ct_OCT_STM_NotSupport	= '0',///未支持的类型
	Ct_OCT_STM_Continental	= 'E',///欧式	48
	Ct_OCT_STM_American		= 'A',///美式	49
	Ct_OCT_STM_Bermuda		= 'B',///百慕大	50
};


///组合类型
enum CtCombtType
{
	Ct_COMBT_NotSupport	= '0',///未支持的类型
	Ct_COMBT_Futures	= 'F',///期货组合	
	Ct_COMBT_BUL		= '1',///垂直价差BUL	
	Ct_COMBT_BER		= '2',///垂直价差BER	
	Ct_COMBT_STD		= '3',///跨式组合	
	Ct_COMBT_STG		= '4',///宽跨式组合	
	Ct_COMBT_PRT		= '5',///备兑组合	
	Ct_COMBT_CLD		= 'T',///时间价差组合	
};


#endif
