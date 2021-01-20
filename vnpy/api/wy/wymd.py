import threading
from wy_md import py_wymd, OK_CODE, OK_OPTIONCODE, OK_FUT_CODE, OK_FUT_OPTIONCODE
import logging
from datetime import datetime

kConnected = 0

def gb2utf8(gbs: bytes):
    return gbs.decode('gb2312', errors='replace')

def ok2dict(o):
    t = type(o)
    if t == OK_CODE:
        return {"id": o.InstrumentID,
                "name": gb2utf8(o.InstrumentName),
                "block": o.blkType
                }
    elif t == OK_OPTIONCODE:
        return {"id": o.InstrumentID,
                "name": gb2utf8(o.InstrumentName),
                "block": o.blkType,
                "exch_id": o.ExchangeID,
                "underlying_id": o.UnderlyingInstrID,
                "call_or_put": o.CtOptCPType,
                "opt_style": o.CtOptStrikeModeType,
                "tick_size": o.PriceTick,
                "strike_price": o.StrikePrice,
                "multiplier": o.VolumeMultiple,
                "open_date": o.OpenDate,
                "expire_date": o.ExpireDate
                }
    elif t == OK_FUT_CODE:
        return {"id": o.InstrumentID,
                "name": gb2utf8(o.InstrumentName),
                "block": o.blkType,
                "exch_id": o.ExchangeID,
                "product_id": o.ProductID,
                "instrument_type": o.ProductClass,
                "combo_type": o.CombinationType,
                "tick_size": o.PriceTick,
                "strike_price": o.StrikePrice,
                "multiplier": o.VolumeMultiple,
                "open_date": o.OpenDate,
                "expire_date": o.ExpireDate,
                "is_trading": o.IsTrading
                }
    elif t == OK_FUT_OPTIONCODE:
        return {"id": o.InstrumentID,
                "name": gb2utf8(o.InstrumentName),
                "block": o.blkType,
                "exch_id": o.ExchangeID,
                "product_id": o.ProductID,
                "instrument_type": o.ProductClass,
                "underlying_id": o.UnderlyingInstrID,
                "call_or_put": o.CtOptCPType,
                "opt_style": o.CtOptStrikeModeType,
                "tick_size": o.PriceTick,
                "strike_price": o.StrikePrice,
                "multiplier": o.VolumeMultiple,
                "underlying_multiplier": o.UnderlyingMultiple,
                "open_date": o.OpenDate,
                "expire_date": o.ExpireDate
                }
    else:
        assert False   

class PyMdApi(py_wymd):
    """"""

    def __init__(self):
        """
        Constructor
        """
        super().__init__()

        #self.gateway = gateway
        #self.gateway_name = gateway.gateway_name
        self.connect_status = False
        self.subscribed = set()
        #TODO: just for testing
        self.logger = logging.getLogger()
        self.logger.setLevel(logging.DEBUG)
        today_date = datetime.now().strftime("%Y%m%d")
        filename = f"vt_{today_date}.log"
        file_handler = logging.FileHandler(
            filename, mode="a", encoding="utf8"
        )
        file_handler.setFormatter(logging.Formatter(
            "[%(threadName)s][%(asctime)s][%(levelname)s][%(funcName)s]: %(message)s"
        ))
        file_handler.setLevel(logging.DEBUG)
        self.logger.addHandler(file_handler)
        console_handler = logging.StreamHandler()
        console_handler.setFormatter(logging.Formatter(
            "[%(threadName)s][%(asctime)s][%(levelname)s][%(funcName)s]: %(message)s"
        ))
        console_handler.setLevel(logging.DEBUG)
        self.logger.addHandler(console_handler)
        self.logger.info("Init")
        self.known_code_list = False


    

    def connect(self, address: str, port: int):
        """
        Start connection to server.
        """
        self.logger.info(f"connecting to {address}:{port}")
        super().connect(address, port)

    def subscribe(self, tup):
        """
        Subscribe to tick data update.
        """
        self.logger.info(f"subscribe")
        super().subscribe(tup)
        #TODO
        

    def close(self):
        """
        Close the connection.
        """
        self.logger.info(f"close")
        self.unsubscribe()

    def OnServerQuoteDisconnected(self):
        self.logger.info(f"OnServerQuoteDisconnected status_before:={self.connect_status}")
        self.connect_status = False


    def OnServerQuoteReconnected(self):
        self.logger.info(f"OnServerQuoteReconnected status_before:={self.connect_status}")
        self.connect_status = True


    def OnConnect(self, ret):
        """
        Callback when server is connected.
        ret:=kConnected indicates success
        """
        self.connect_status = ret == kConnected
        self.logger.info(f"connect_status:={self.connect_status} (return code:={ret})")

    def OnCodeListVector(self, sec_codes, secopt_codes, fut_codes, futopt_codes, trading_day):
        self.logger.info(f"OnCodeList: stocks [{len(sec_codes)}], stock_options [{len(secopt_codes)}]"
        f"futures [{len(fut_codes)}], futopt_codes [{len(futopt_codes)}], trading_day [{trading_day}]")
        self.known_code_list = True

    def OnIndRealData(self, ):
        """
        
        """
        self.logger.info("OnIndRealData")

    def OnSecRealDataL1(self):
        """
        """
        pass

    def OnSecRealDataL2(self):
        """
        """
        pass

if __name__ == '__main__':
    session = PyMdApi()
    session.connect("192.168.10.5", 27015)
    from threading import Thread
    from time import sleep, time
    start = time()
    while session.connect_status == False:
        sleep(1)
    session.subscribe((True, False, False, False, False, "", "10002712"))
    while session.known_code_list == False and (time() - start < 120):
        sleep(1)
    sleep(10)
    print('here')