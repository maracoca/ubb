import math

def function(x):
    return math.exp(-x**2)

def trapezium_rule(a, b, function):
    n = 1000
    width_of_subintervals = (b - a) / n
    integral_sum = 0.5 * width_of_subintervals * (function(b) - function(a))
    for i in range(n):
        integral_sum += width_of_subintervals * function(a + (i + 1) * width_of_subintervals)
    return integral_sum

def approximate():
    values = [10, 50, 100, 200, 500, 1000]
    expected_result = math.sqrt(math.pi)
    for i in values:
        numerical_result = trapezium_rule(-i, i, function)
        print(f"a= {i}")
        print(f"Numerical result: {numerical_result}")
        print(f"Expected result: {expected_result}")


approximate()