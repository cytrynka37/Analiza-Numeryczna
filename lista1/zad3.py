import numpy as np
import pandas as pd

def f_single(x):
    x = np.float32(x)
    return np.float32(1518 * (2 * x - np.sin(2 * x)) / (x ** 3))

def f_double(x):
    x = np.float64(x)
    return np.float64(1518 * (2 * x - np.sin(2 * x)) / (x ** 3))

results_single = []
results_double = []

for i in range(1, 10):
    x = 10**(-i)
    results_single.append(f_single(x))
    results_double.append(f_double(x))

df = pd.DataFrame({
    'i': range(1, 10),
    '(Single Precision)': results_single,
    '(Double Precision)': results_double
})

print(df)

#Problem wiąże się z utratą precyzji. w pewnym momencie sin2x jest bardzo bliski zera, a wtedy 2x - sin2x = 0. Wtedy f(x) = 0.
#Oczywiście problem powstaje później dla podwójnej precyzji, ponieważ mieści więcej cyfr.