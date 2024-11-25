import matplotlib.pyplot as plt
import numpy as np

def chebyshev_nodes(n):
    k = np.arange(n)
    nodes = np.cos((2*k + 1)*np.pi/(2*n))
    return nodes

def create_polynomial(nodes):
    polynomial = np.poly1d([1])
    for node in nodes:
        polynomial *= np.poly1d([1, -node])
    return polynomial

for i in range(4, 21):
    p = create_polynomial(np.linspace(-1, 1, i + 1))
    c = create_polynomial(chebyshev_nodes(i + 1))
    x = np.linspace(-1, 1, 1000)

    plt.plot(x, p(x), label="węzły równoodległe")
    plt.plot(x, c(x), label="węzły Czebyszewa")

    plt.title(f"Wielomian dla n = {i}")
    plt.legend()

    nr = str(i) if i > 9 else "0" + str(i)
    name = "graph" + nr + ".png"
    plt.savefig(name)
    plt.close()