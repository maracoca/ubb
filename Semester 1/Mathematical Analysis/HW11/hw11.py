#Mara Anastasia Cocaina. 912
import numpy as np
import matplotlib.pyplot as plt

def f(x, A):
    return 0.5 * np.dot(x.T, np.dot(A, x))
def plot_surface(A, title):
    x = np.linspace(-5, 5, 100)
    y = np.linspace(-5, 5, 100)
    X, Y = np.meshgrid(x, y)
    Z = np.array([f(np.array([xi, yi]), A) for xi, yi in zip(X.flatten(), Y.flatten())])
    Z = Z.reshape(X.shape)

    fig = plt.figure(figsize=(12, 8))
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(X, Y, Z, cmap='viridis', alpha=0.7)
    ax.contour(X, Y, Z, zdir='z', offset=np.min(Z), cmap='viridis')

    points = np.array([[2, 2], [-2, -2], [2, -2]])
    gradients = np.array([np.dot(A, point) for point in points])
    for i, point in enumerate(points):
        grad = gradients[i]
        ax.quiver(point[0], point[1], f(point, A), grad[0], grad[1], -f(point, A), color='red', length=0.5, normalize=True)
    ax.set_title(title)
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('f(x)')
    plt.show()

A_min = np.array([[2, 0], [0, 2]])
plot_surface(A_min, 'Unique Minimum')
A_max = np.array([[-2, 0], [0, -2]])
plot_surface(A_max, 'Unique Maximum')
A_saddle = np.array([[2, 0], [0, -2]])
plot_surface(A_saddle, 'Unique Saddle Point')
