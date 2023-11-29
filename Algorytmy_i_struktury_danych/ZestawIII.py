import random
import math

# Definicja funkcji Easoma


def easom(x, y):
    return -math.cos(x) * math.cos(y) * math.exp(-(x - math.pi)**2 - (y - math.pi)**2)


# Parametry algorytmu PSO
num_particles = 30
max_iterations = 100
w = 0.5  # Współczynnik inercji
c1 = 1.5  # Współczynnik przyciągania osobistego
c2 = 1.5  # Współczynnik przyciągania globalnego

# Inicjalizacja cząstek
particles = []
global_best_position = (random.uniform(-100, 100), random.uniform(-100, 100))
global_best_value = easom(global_best_position[0], global_best_position[1])

for _ in range(num_particles):
    x = random.uniform(-100, 100)
    y = random.uniform(-100, 100)
    position = (x, y)
    velocity = (random.uniform(-1, 1), random.uniform(-1, 1))
    personal_best_position = position
    personal_best_value = easom(x, y)

    particles.append((position, velocity, personal_best_position, personal_best_value))

# Główna pętla PSO
for iteration in range(max_iterations):
    for i, (position, velocity, personal_best_position, _) in enumerate(particles):
        x, y = position

        # Obliczenie wartości funkcji Easoma w aktualnej pozycji
        current_value = easom(x, y)

        # Aktualizacja osobistego najlepszego rozwiązania
        if current_value < particles[i][3]:
            particles[i] = (position, velocity, position, current_value)

            # Aktualizacja globalnego najlepszego rozwiązania
            if current_value < global_best_value:
                global_best_position = position
                global_best_value = current_value

    for i, (position, velocity, personal_best_position, _) in enumerate(particles):
        x, y = position
        vx, vy = velocity
        px, py = personal_best_position

        # Aktualizacja prędkości i pozycji cząstki
        new_velocity = (
            w * vx + c1 * random.random() * (px - x) + c2 * random.random() * (global_best_position[0] - x),
            w * vy + c1 * random.random() * (py - y) + c2 * random.random() * (global_best_position[1] - y)
        )

        new_position = (x + new_velocity[0], y + new_velocity[1])
        particles[i] = (new_position, new_velocity, personal_best_position, personal_best_value)

# Wynik
print("Global minimum found at position:", global_best_position)
print("Minimum value of Easom function:", global_best_value)
