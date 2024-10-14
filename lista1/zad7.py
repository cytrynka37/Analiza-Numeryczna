import math

def sin_taylor(x, b=1e-10):
    x = x % (2 * math.pi)
    
    a = x
    sum_sin = a  
    n = 0
    
    while abs(a) > b:
        a *= -x**2 / ((2*n + 2) * (2*n + 3))
        sum_sin += a
        print(sum_sin)
        n += 1
        
    return sum_sin


x = math.pi / 4
sin_approx = sin_taylor(x)
sin_lib = math.sin(x)

print(f"Wartość sin(x) z algorytmu Taylora: {sin_approx}")
print(f"Wartość sin(x) z funkcji bibliotecznej: {sin_lib}")
print(f"Różnica: {abs(sin_approx - sin_lib)}")