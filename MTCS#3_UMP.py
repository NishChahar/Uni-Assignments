import math as m
import numpy as np
import GoldenSectionMethod


def GSR(f):
    y= f(1)
    print(y)


def Fib(f):
    y= f(2)
    print(y)


def TSD(f):
    y= f(3)
    print(y)


def Newton(f):
    y= f(4)
    print(y)


def Conjugate(f):
    y= f(5)
    print(y)


def select(f):
    print("Which method you would like to choose")
    print("1.Golden Section Rule")
    print("2.Fibonacci Search Method")
    print("3.The Steepest Descent Method")
    print("4.Newton's Method")
    print("5.Conjugate Gradient Method")
    ch = input()
    switch(ch,f)


def switch(ch,f):
    if ch==1:
        GSR(f)
    elif ch==2:
        Fib(f)
    elif ch==3:
        TSD(f)
    elif ch==4:
        Newton(f)
    elif ch==5:
        Conjugate(f)
    else:
        print("Invalid Choice")


if __name__ == "__main__":
    print("Input the objective funtion")
    f = lambda x: eval(input())
    y=f(3)
    print(y)
    select(f)