import sys
from io import StringIO

def test_print(monkeypatch):
    monkeypatch.setattr(sys, "stdout", StringIO())
    print("hello")
    assert sys.stdout.getvalue() == "hello\n"
