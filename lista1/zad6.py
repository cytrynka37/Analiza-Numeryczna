# Obliczanie wartości π przy użyciu szeregu naprzemiennego

def calculate_pi(terms):
    pi_approx = 0.0
    for k in range(terms):
        pi_approx += (-1)**k / (2*k + 1)
    return 4 * pi_approx

# Liczba wyrazów, aby uzyskać błąd < 10^-6
terms = 199998
pi_value = calculate_pi(terms)
print(f"Przybliżona wartość π z {terms} wyrazami: {pi_value}")

# Rzeczywista wartość π dla porównania
import math
actual_pi = math.pi
print(f"Rzeczywista wartość π: {actual_pi}")
print(f"Błąd bezwzględny: {abs(pi_value - actual_pi)}")