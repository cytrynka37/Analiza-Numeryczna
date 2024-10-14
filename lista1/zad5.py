import numpy as np

# Ustawienia początkowe
I_0 = np.log(2024 / 2023)  # Wartość I_0 w podwójnej precyzji (domyślnie float)
n_max = 20  # Maksymalna wartość n
I_values = [0.0] * (n_max + 1)  # Tablica na wartości I_n (float)
I_values[0] = I_0


for n in range(1, n_max + 1):
    I_values[n] = (1.0 / n) - 2023.0 * I_values[n-1]

for n in range(1, n_max + 1):
    print(f'I_{n} = {I_values[n]:.15f}')


print("\nPodciąg I_1, I_3, ..., I_19:")
for n in range(1, n_max + 1, 2):
    print(f'I_{n} = {I_values[n]:.15f}')

print("\nPodciąg I_2, I_4, ..., I_20:")
for n in range(2, n_max + 1, 2):
    print(f'I_{n} = {I_values[n]:.15f}')
