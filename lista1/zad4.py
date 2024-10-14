def f(n):
    y_values = [0] * (n + 1)
    y_values[0] = 1
    y_values[1] = -1 / 6

    for i in range(2, n + 1):
        y_values[i] = (35 / 6) * y_values[i - 1] + y_values[i - 2]

    return y_values

for value in f(50):
    print(value)