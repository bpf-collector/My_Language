import os
from ctypes import cdll
#include <string.h>

def menu(get = 0):
    if not get:
        print("{0:=^80}".format(""))
        print("{0:=^80}".format("        Prime        "))
        print("* 判断素数\n** 获取素数\n*** 查找素数")
    print("{0:=<70} 请选择：".format(""), end='')
    return len(input())

def process(choose):
    if choose == 1:
        num = int(input("请输入一个整数："))
        if prime.isPrime(num):
            print("{} 是素数".format(num))
        else:
            print("{} 不是素数".format(num))
    elif choose == 2:
        p = []
        print("请设置：")
        start = int(input("请输入开始值(整数):"))
        end = int(input("请输入结束值(整数):"))
        step = int(input("请输入步长值(整数):"))
        prime.getPrime(id(p), start, end, step)
        print("其中的素数为：", end = '')
        prime.printPrime(id(p))
    elif choose == 3:
        return;
        p = [0 for i in range(10)]
        Sp = input("请输入数组(空格分开): ")
        Np = [int(n) for n in Sp.split()]
        prime.findPrime(id(Np), len(Np), id(p))
        print("其中的素数为：", end = '')
        prime.printPrime(id(p))
    else:
        print("输入错误!")
        menu(1)

if __name__ == "__main__":
    # 加载模块
    prime = cdll.LoadLibrary(os.getcwd() + '\prime_.dll')
    #prime.test()
    choose = 10
    while(choose):
        choose = menu(0)
        process(choose)