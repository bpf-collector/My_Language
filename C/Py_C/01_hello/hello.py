from ctypes import cdll
hi = cdll.LoadLibrary('.\\hello.dll')
hi.pt()