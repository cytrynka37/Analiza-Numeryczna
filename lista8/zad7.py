import matplotlib.pyplot as plt

ts = [k / 27 for k in range(28)]
xs = [15.5, 12.5, 8, 10, 7, 4, 8, 10, 9.5, 14, 18, 17, 22, 25, 19, 24.5, 23, 17, 16, 12.5, 16.5, 21, 17, 11, 5.5, 7.5, 10, 12]
ys = [32.5, 28.5, 29, 33, 33, 37, 39.5, 38.5, 42, 43.5, 42, 40, 41.5, 37, 35, 33.5, 29.5, 30.5, 32, 19.5, 24.5, 22, 15, 10.5, 2.5, 8, 14.5, 20]

def eval_h(xs):
    h = [0]
    for i in range(1, len(xs)):
        h.append(xs[i] - xs[i - 1])

    return h

def eval_lambda(h):
    lambdas = [0]
    for i in range(1, len(h) - 1):
        lambdas.append(h[i] / (h[i] + h[i + 1]))
    
    return lambdas

def eval_pq(lambdas):
    p = [0]
    q = [0]
    for i in range(1, len(lambdas)):
        p.append(lambdas[i] * p[i - 1] + 2)
        q.append ((lambdas[i] - 1) / p[i])

    return p, q

def eval_u(lambdas, p):
    u = [0]
    for i in range(1, len(xs) - 1):
        f1 = (ys[i + 1] - ys[i]) / (xs[i + 1] - xs[i])
        f2 = (ys[i] - ys[i - 1]) / (xs[i] - xs[i - 1])
        d = 6 * ((f1 - f2) / (xs[i + 1] - xs[i - 1]))
        u.append((d - lambdas[i] * u[i - 1]) / p[i])
    
    return u

def eval_M(u, qs):
    M = [u[-1]]
    len_u = len(u)
    for i in range(1, len_u):
        M.append(u[len_u - i] + qs[len_u - i] * M[i - 1])

    M.append(0)
    M = M[::-1]
    return M

def eval_sk(h, M, x, xs, ys, k):
    return (
          (1/6) * M[k - 1] * (xs[k] - x)**3
        + (1/6) * M[k] * (x - xs[k - 1])**3
        + (ys[k - 1] - (1/6) * M[k - 1] * h[k] ** 2) * (xs[k] - x)
        + (ys[k] - (1/6) * M[k] * h[k] ** 2) * (x - xs[k - 1])
        ) / h[k]

def eval_s(x, y, p, q, lamb, h):
    u = eval_u(lamb, p)
    M = eval_M(u, q)
    ys = []
    i = 1
    a = 150
    for k in range(a):
        if (k/a > x[i]):
            i += 1
        else:
            ys.append(eval_sk(h, M, k/a, x, y, i))

    return ys


lamb = eval_lambda(ts)
p, q = eval_pq(lamb)
h = eval_h(ts)

x_result = eval_s(ts, xs, p, q, lamb, h)
y_result = eval_s(ts, ys, p, q, lamb, h)

plt.plot(x_result, y_result, color='red')
plt.savefig("zagadka.png")