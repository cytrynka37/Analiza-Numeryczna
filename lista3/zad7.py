import math
import numpy as np

def f_original(x):
    return (8096 * (np.sqrt(np.float64(x)**13 + 4) - 2)) / (np.float64(x)**14)

def f_improved(x):
    return 8096 / (np.float64(x) * (np.sqrt(np.float64(x)**13 + 4) + 2))

x = 0.001
print(f_original(x), f_improved(x))
