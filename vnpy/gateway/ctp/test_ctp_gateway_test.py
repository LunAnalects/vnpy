import pytest

@pytest.fixture
def ctp_gw():
    from .ctp_gateway import CtpGateway, NullCtpMdApi, NullCtpTdApi
    from vnpy.event.engine import EventEngine
    ee = EventEngine()
    return CtpGateway(ee, NullCtpTdApi, NullCtpMdApi)

setting = {"用户名": "",
           "密码": "",
           "经纪商代码": "",
           "交易服务器": "",
           "行情服务器": "",
           "产品名称": "",
           "授权编码":"",
           "产品信息":""}
def test_init(ctp_gw):
    ctp_gw.connect(setting)
    assert True