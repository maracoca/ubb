import matplotlib.pyplot as plt
import numpy as np


def plot_value(p_norm):
    x = np.random.random_sample((10000))
    list_x = []

    for _ in range(2):
        for i in x:
            list_x.append(i)

    for _ in range(2):
        for i in x:
            list_x.append(-i)

    y = []
    list_y = []

    for i in x:
        y.append(np.power(1 - np.power(i, p_norm), 1.0 / p_norm))

    for _ in range(2):
        for i in y:
            list_y.append(i)

        for i in y:
            list_y.append(-i)

    y = np.random.random_sample((10000))
    x = []

    for i in y:
        x.append(np.power(1 - np.power(i, p_norm), 1.0 / p_norm))

    for _ in range(2):
        for i in x:
            list_x.append(i)

    for _ in range(2):
        for i in x:
            list_x.append(-i)

    for _ in range(2):
        for i in y:
            list_y.append(i)
        for i in y:
            list_y.append(-i)

    plt.title(f"p= {p_norm}")
    plt.plot(list_x, list_y, "go")
    plt.show()


plot_value(0.25)
plot_value(0.75)
plot_value(1.25)
plot_value(1.5)
plot_value(2)
plot_value(3)
plot_value(8)
plot_value(20)
plot_value(100)