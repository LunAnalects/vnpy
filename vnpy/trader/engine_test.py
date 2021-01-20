"""
"""
import pytest
from typing import Dict, Any
from unittest.mock import patch, mock_open
from .setting import SETTINGS
from .engine import MainEngine, TRADING


@patch('builtins.open', new_callable=mock_open, create=True)
def test_log_nonblocking(m):
    SETTINGS['log.file.nonblocking'] = True
    SETTINGS['log.file'] = True
    me = MainEngine()
    me.close()
    me = None
    mfile = m.return_value.__enter__.return_value
    mfile.write.assert_called()


@patch('builtins.open', new_callable=mock_open, create=True)
def test_level(m):
    SETTINGS['log.level'] = TRADING
    me = MainEngine()
    me.close()
    me = None
    mfile = m.return_value.__enter__.return_value
    assert mfile.write.call_count == 0