import matplotlib.pyplot as plt
import numpy as np

def f(x, y, b):
    return (x ** 2 + b * (y ** 2)) / 2

def step(x, y, b):
    return (x ** 2 + 2 * (b ** 2) * (y ** 2)) / (x ** 2 + 2 * (b ** 3) * (y ** 2))

def update_variables(x, y, step_size, b):
    return [(1 - step_size) * x, (1 - b * step_size) * y]

b_values = [1 / 2, 1 / 5, 1 / 10]

for b in b_values:
    iterations = 10
    x = np.zeros(iterations + 2)
    y = np.zeros(iterations + 2)

    x[0] = 1
    y[0] = 1

    current_iteration = 0
    step_size = step(x[current_iteration], y[current_iteration], b)
    [x[current_iteration + 1], y[current_iteration + 1]] = update_variables(x[current_iteration], y[current_iteration], step_size, b)

    while current_iteration < iterations and not (x[current_iteration + 1] == 0 and y[current_iteration + 1] == 0):
        current_iteration += 1
        step_size = step(x[current_iteration], y[current_iteration], b)
        [x[current_iteration + 1], y[current_iteration + 1]] = update_variables(x[current_iteration], y[current_iteration], step_size, b)

    x_list = np.linspace(-2.0, 2.0, 50)
    y_list = np.linspace(-2.0, 2.0, 50)
    X, Y = np.meshgrid(x_list, y_list)
    Z = f(X, Y, b)

    contours = plt.contour(X, Y, Z, levels=50)
    plt.clabel(contours, inline=True, fontsize=8)
    plt.plot(x[:iterations], y[:iterations], 'r--o')
    plot_title = "b = " + str(b)
    plt.title(plot_title)

    plt.show()
