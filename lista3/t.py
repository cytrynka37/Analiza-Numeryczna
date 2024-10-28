from math import *

#a
def cosinus(x): #przekształcenia nr1
    a = x - pi/6
    c = cos(a)*cos(pi/6)
    s = sin(a)*sin(pi/6)
    return c - s


def cosinus2(x): #wzór Taylora
    return 1 - x**2 / 2 + x**4/24



def f(x): #bezpośrednio
    return 4*(cosinus(x))**2 - 3


def f1(x): #z wykorzystaniem przekształceń nr1
    return 4 * (cosinus2(x)) ** 2 - 3


def f2(x): #przekształcenia nr2
    s = sin(x - pi/6)*sin(x + pi/6)
    return -4 * s


x0 = [pi/6 + 0.001*k for k in range(-5, 6)]
y1 = []
y2 = []
y3 = []
y4 = []
for x in x0:
    y1.append(f(x))
    y2.append(4*(cos(x))**2 - 3)
    y3.append(f1(x))
    y4.append(f2(x))


print(y1)
print(y2)
print(y3)
print(y4)