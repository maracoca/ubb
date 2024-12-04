# from random import randint
# import timeit
# def exchange_sort(unsorted: list):
#     """
#     Function that sorts a list with the Exchange Sort Algorithm and calculates its complexity
#     :param unsorted: the randomly generated list that needs to be sorted
#
#
#     Best Case: O(n *(n-1)/2) = O(n^2)  it goes through the whole for, even if there are no swaps needed
#     Average Case: O(n^2)
#     Worst Case: O(n *(n-1)/2) = O(n^2)
#     """
#     list_size = len(unsorted)
#     start_complexity = timeit.default_timer()
#     print(start_complexity)
#     for i in range(0, list_size - 1):         #1...list_size
#         for j in range(i + 1, list_size):     #(list_size - 1) ...1
#             if unsorted[i] > unsorted[j]:
#                 unsorted[i], unsorted[j] = unsorted[j], unsorted[i]
#     end_complexity = timeit.default_timer()
#     print(end_complexity)
#     execution_time = (end_complexity - start_complexity)
#     return execution_time
#
# number_of_values = input("How long do you want your first list to be? ")
# random_list = []
# for i in range(int(number_of_values)):
#     values = randint(0, 100)
#     random_list.append(values)
# random_list.sort()
# random_list.reverse()
# x=exchange_sort(random_list)
# print(x)

import timeit

def exchange_sort(arr):
    n = len(arr)
    comparisons = 0
    swaps = 0
    for i in range(0, n - 1):
        for j in range(i+1, n ):
            comparisons += 1
            if arr[i] > arr[j ]:
                swaps += 1
                arr[i], arr[j] = arr[j], arr[i]
    return comparisons, swaps

# Generate a list sorted in reverse order
def generate_reverse_sorted_list(size):
    return list(range(size, 0, -1))

# Measure the execution time for worst-case scenario
array_sizes = [10, 100, 1000, 10000, 100000]
for size in array_sizes:
    arr = generate_reverse_sorted_list(size)
    timer = timeit.default_timer()
    comparisons, swaps = exchange_sort(arr)
    elapsed_time = timeit.default_timer() - timer
    print(f"Array size: {size}, Comparisons: {comparisons}, Swaps: {swaps}, Time: {elapsed_time:.6f} seconds")


def complexity_heap_sort(number_of_values: int, number_of_current_values: int, option: str):
    random_list = []
    best_random_list = []
    worst_random_list = []
    for i in range(0, 5):
        random_list = generate_list(number_of_current_values)
        if (option == "1"):
            best_random_list = best_case(random_list)
            complexity_exchange_sort = heap_sort(random_list)
        elif (option == "2"):
            worst_random_list = worst_case(random_list)
            complexity_exchange_sort = heap_sort(random_list)
        else:
            complexity_exchange_sort = heap_sort(random_list)
        print("Exchange sort")
        print("The best time complexity for a list of ", number_of_current_values, " elements is ", complexity_exchange_sort)
        number_of_current_values = int(number_of_current_values) * 2
        random_list = []
    number_of_current_values = number_of_values



def complexity_exchange_sort(number_of_values: int, number_of_current_values: int, option: str):
    random_list = []
    best_random_list = []
    worst_random_list = []
    for i in range(0, 5):
        random_list = generate_list(number_of_current_values)
        if (option == "1"):
            best_random_list = best_case(random_list)
            complexity_exchange_sort = heap_sort(best_random_list)
        elif (option == "2"):
            worst_random_list = worst_case(random_list)
            complexity_exchange_sort = heap_sort(worst_random_list)
        else:
            complexity_exchange_sort = heap_sort(random_list)
        print("Exchange sort")
        print("The best time complexity for a list of ", number_of_current_values, " elements is ", complexity_exchange_sort)
        number_of_current_values = int(number_of_current_values) * 2
        random_list = []
    number_of_current_values = number_of_values

    def best_case(random_list: list):
        random_list.sort()

    def worst_case(random_list: list):
        random_list.sort()
        random_list.reverse()