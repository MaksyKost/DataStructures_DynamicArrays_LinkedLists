import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression

# Dane wejściowe
sizes = np.array([10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]).reshape(-1, 1)

# Czas wyszukiwania dla każdej struktury danych
array_times = np.array([3.03e-08, 3.18e-08, 2.92e-08, 3.07e-08, 3.1e-08, 2.66e-08, 2.95e-08, 3.06e-08, 2.99e-08, 2.92e-08])
slist_times = np.array([3.63e-08, 3.44e-08, 3.85e-08, 5.62e-08, 6.56e-08, 6.82e-08, 6.92e-08, 6.71e-08, 8.35e-08, 6.98e-08])
dlist_times = np.array([1.0282e-05, 1.18916e-05, 1.47976e-05, 1.12581e-05, 2.1557e-05, 1.76398e-05, 2.88055e-05, 2.32827e-05, 1.54711e-05, 2.48044e-05])

# Modele regresji
reg_array = LinearRegression().fit(sizes, array_times)
reg_slist = LinearRegression().fit(sizes, slist_times)
reg_dlist = LinearRegression().fit(sizes, dlist_times)

# Przewidywane wartości
sizes_flat = sizes.flatten()
pred_array = reg_array.predict(sizes)
pred_slist = reg_slist.predict(sizes)
pred_dlist = reg_dlist.predict(sizes)

# Funkcja do rysowania wykresów
def plot_with_fit(x, y, y_pred, title, label, color):
    plt.figure(figsize=(8, 5))
    plt.scatter(x, y, color=color, label=f'Czas ({label})', marker='o')
    plt.plot(x, y_pred, color='black', linestyle='--', label='Dopasowanie liniowe')
    plt.title(title)
    plt.xlabel('Rozmiar struktury danych')
    plt.ylabel('Czas [s]')
    plt.grid(True, linestyle='--', alpha=0.6)
    plt.legend()
    plt.tight_layout()
    plt.show()

# Rysowanie wykresów
plot_with_fit(sizes_flat, array_times, pred_array, 'Czas wyszukiwania - Tablica dynamiczna', 'Tablica', 'blue')
plot_with_fit(sizes_flat, slist_times, pred_slist, 'Czas wyszukiwania - Lista jednokierunkowa', 'Lista jednokierunkowa', 'red')
plot_with_fit(sizes_flat, dlist_times, pred_dlist, 'Czas wyszukiwania - Lista dwukierunkowa', 'Lista dwukierunkowa', 'green')
