#Mara-Anastasia Cocaina

import numpy as np
import matplotlib.pyplot as plt

def convex_function(x):
    return x**2

def nonconvex_function(x):
    return x**3

def gradient_for_convex_function(x):
    return 2 * x

def gradient_for_nonconvex_function(x):
    return 3*x**2

def gradient_descent_method(option, learning_rate, iterations, initial_value):
    path = []
    x = initial_value

    if option == "a" or option == "b" or option == "c":
        for i in range(iterations):
            x = x - learning_rate * gradient_for_convex_function(x)
            path.append(x)
    else:
        for i in range(iterations):
            x = x - learning_rate * gradient_for_nonconvex_function(x)
            path.append(x)

    return x, path

def main():
    while True:
        print("(a) Take a convex f and show that for small learning rate the gradient descent method converges to the minimum of f.")
        print("(b) Show that by increasing the learning rate the gradient descent method can converge faster (in fewer steps).")
        print("(c) Show that taking the learning rate too large might lead to the divergence of the method.")
        print("(d) Take a nonconvex f and show that the method can get stuck in a local minimum.")
        user_option = str(input("Choose an option: "))
        if user_option == "a":
            learning_rate = 0.01
            iterations = 5000
            initial_value = 5
            minimum, path = gradient_descent_method(user_option, learning_rate, iterations, initial_value)
        elif user_option == "b":
            learning_rate = 0.1
            iterations = 50
            initial_value = 5
            minimum, path = gradient_descent_method(user_option, learning_rate, iterations, initial_value)
        elif user_option == "c":
            learning_rate = 1
            iterations = 50
            initial_value = 5
            minimum, path = gradient_descent_method(user_option, learning_rate, iterations, initial_value)
        elif user_option == "d":
            learning_rate = 0.1
            iterations = 100
            initial_value = 2
            minimum, path = gradient_descent_method(user_option, learning_rate, iterations, initial_value)
        else:
            return 0

        if user_option == "a" or user_option == "b" or user_option == "c":
            x = np.linspace(-10, 10, 100)
            y = convex_function(x)

            plt.plot(x, y, label="Convex Function")
            if user_option == "a":
                plt.plot(path, [convex_function(x) for x in path], marker='o', label="Gradient Descent Path For Small Learning Rate")
            if user_option == "b":
                plt.plot(path, [convex_function(x) for x in path], marker='o', label="Gradient Descent Path For Increased Learning Rate")
            if user_option == "c":
                plt.plot(path, [convex_function(x) for x in path], marker='o', label="Gradient Descent Path For Large Learning Rate")

        else:
            x = np.linspace(-2, 5, 100)
            y = nonconvex_function(x)

            plt.plot(x, y, label="Nonconvex Function")
            plt.plot(path, [nonconvex_function(x) for x in path], marker="o", label="Gradient Descent Path For Nonconvex Function")

        plt.xlabel("x")
        plt.ylabel("f(x)")
        plt.legend()
        plt.title("Gradient Descent Method")
        plt.grid(True)
        plt.show()

        print(f"Minimum found by gradient descent: {minimum}")

main()