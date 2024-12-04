import timeit
from random import randint

def generate_random_list(number_of_values: int):
    random_list = []
    for i in range(1, int(number_of_values) + 1):
        values = randint(0, 100)
        random_list.append(values)
    return random_list


def print_complexity_exchange_sort(number_of_values: int, number_of_current_values: int, option: str, complexity_exchange_sort):
    random_list = []
    for i in range(0, 5):
        random_list = generate_random_list(number_of_current_values)
        if (option == "1"):
            random_list.sort()
            complexity_exchange_sort = exchange_sort(random_list)
        elif (option == "2"):
            random_list.sort()
            random_list.reverse()
            complexity_exchange_sort = exchange_sort(random_list)
        else:
            complexity_exchange_sort = exchange_sort(random_list)
        print("Exchange sort")
        print("The best time complexity for a list of ", number_of_current_values, " elements is ", complexity_exchange_sort)
        number_of_current_values = int(number_of_current_values) * 2
        random_list = []
    number_of_current_values = number_of_values

def print_complexity_heap_sort(number_of_values: int, number_of_current_values: int, option: str, complexity_heap_sort):
    random_list = []
    for i in range(0, 5):
        random_list = generate_random_list(number_of_current_values)
        if (option == "1"):
            random_list.sort()
            complexity_heap_sort = heap_sort(random_list)
        elif (option == "2"):
            random_list.sort()
            random_list.reverse()
            complexity_heap_sort = heap_sort(random_list)
        else:
            complexity_heap_sort = heap_sort(random_list)
        print("Heap sort")
        print("The best time complexity for a list of ", number_of_current_values, " elements is ", complexity_heap_sort)
        number_of_current_values = int(number_of_current_values) * 2
        random_list = []
    number_of_current_values = number_of_values


def exchange_sort(unsorted: list):
    """
    Function that sorts a list with the Exchange Sort Algorithm and calculates its complexity
    :param unsorted: the randomly generated list that needs to be sorted


    Best Case: O(n *(n-1)/2) = O(n^2)  it goes through the whole for, even if there are no swaps needed
    Average Case: O(n^2)
    Worst Case: O(n *(n-1)/2) = O(n^2)
    """
    list_size = len(unsorted)
    start_complexity = timeit.default_timer()
    for i in range(0, list_size - 1):         #1...list_size
        for j in range(i + 1, list_size):     #(list_size - 1) ...1
            if unsorted[i] > unsorted[j]:
                unsorted[i], unsorted[j] = unsorted[j], unsorted[i]
    end_complexity = timeit.default_timer()
    execution_time = (end_complexity - start_complexity)
    return execution_time

def heapify(unsorted: list, greatest_index: int, parent: int):
    """
    The conversion of the list into a max heap (the greatest element is on index 0 of the list)
    :param unsorted: randomly generated list
    :param greatest_index: the current greatest index that doesn't have the right value
    :param parent: the parent that needs to be compared with its children
    """
    largest_number = parent
    left_child = parent * 2 + 1
    right_child = parent * 2 + 2
    if left_child < greatest_index and unsorted[largest_number] < unsorted[left_child]:
        largest_number = left_child
    if right_child < greatest_index and unsorted[largest_number] < unsorted[right_child]:
        largest_number = right_child
    if largest_number != parent:
        unsorted[parent], unsorted[largest_number] = unsorted[largest_number], unsorted[parent]
        heapify(unsorted, greatest_index, largest_number)

def heap_sort(unsorted: list):
    """
    The elimination of the highest element, the resulted max heap and the complexity of the algorithm
    :param unsorted: randomly generated list

    The complexity of heapify is O(log(n)), as the height of a binary tree of size n is log2(n) at most, We may need
    to swap nodes through the entire height of the tree.
    The first removal of the node is log(n), the second removal of the node is log(n-1), ...
    Best Case: O(log(n) + log(n-1) + log(n-2) + ....log(1)) = O(log n!) = O(n*log n)
    Average Case: O(log(n) + log(n-1) + log(n-2) + ....log(1)) = O(log n!) = O(n*log n)
    Worst Case: O(log(n) + log(n-1) + log(n-2) + ....log(1)) = O(log n!) = O(n*log n) 
    """
    start_complexity = timeit.default_timer()
    list_lenght = len(unsorted)
    for i in range(list_lenght // 2 - 1, -1, -1):
        heapify(unsorted, list_lenght, i)
    for i in range(list_lenght - 1, 0, -1):
        unsorted[i], unsorted[0] = unsorted[0], unsorted[i]
        heapify(unsorted, i, 0)
    end_complexity = timeit.default_timer()
    execution_time = (end_complexity - start_complexity)
    return execution_time

def main():
    random_list = []
    number_of_values = int(input("How long do you want your first list to be? "))
    number_of_current_values = number_of_values
    while True:
        print("1. Show the best complexity.")
        print("2. Show the average complexity.")
        print("3. Show the worst complexity.")
        print("0. Exit the program")
        option = input("Choose a number ")

        if option == "1":
            print_complexity_exchange_sort(number_of_values, number_of_current_values, option, 0)
            print_complexity_heap_sort(number_of_values, number_of_current_values, option, 0)
            # random_list = []
            # copy_of_list = []
            # for i in range(0, 5):
            #     random_list = generate_list(number_of_current_values)
            #     random_list.sort()
            #     complexity_exchange_sort = exchange_sort(random_list)
            #     complexity_heap_sort = heap_sort(random_list)
            #     print("Exchange sort")
            #     print("The best time complexity for a list of ", number_of_current_values, " elements is ", complexity_exchange_sort)
            #     print("Heap Sort")
            #     print("The best time complexity for a list of ", number_of_current_values, " elements is ", complexity_heap_sort)
            #     number_of_current_values = int(number_of_current_values) * 2
            #     random_list = []
            #     copy_of_list = []
            # number_of_current_values = number_of_values


        elif option == "2":
            print_complexity_exchange_sort(number_of_values, number_of_current_values, option, 0)
            print_complexity_heap_sort(number_of_values, number_of_current_values, option, 0)
        #     random_list = []
        #     copy_of_list = []
        #     for i in range(0, 5):
        #         random_list = generate_list(number_of_current_values)
        #         copy_of_list = random_list.copy()
        #         complexity_exchange_sort = exchange_sort(random_list)
        #         complexity_heap_sort = heap_sort(copy_of_list)
        #         print("Exchange sort")
        #         print("The average time complexity for a list of ", number_of_current_values, " elements is ",complexity_exchange_sort)
        #         print("Heap Sort")
        #         print("The average time complexity for a list of ", number_of_current_values, " elements is ", complexity_heap_sort)
        #         number_of_current_values = int(number_of_current_values) * 2
        #         random_list = []
        #         copy_of_list = []
        #     number_of_current_values = number_of_values
        #

        elif option == "3":
            print_complexity_exchange_sort(number_of_values, number_of_current_values, option, 0)
            print_complexity_heap_sort(number_of_values, number_of_current_values, option, 0)
        #     random_list = []
        #     copy_of_list = []
        #     for i in range(0, 5):
        #         random_list = generate_list(number_of_current_values)
        #         random_list.sort()
        #         random_list.reverse()
        #         copy_of_list = random_list.copy()
        #         complexity_exchange_sort = exchange_sort(random_list)
        #         complexity_heap_sort = heap_sort(copy_of_list)
        #         print("Exchange sort")
        #         print("The worst time complexity for a list of ", number_of_current_values, " elements is ", complexity_exchange_sort)
        #         print("Heap Sort")
        #         print("The worst time complexity for a list of ", number_of_current_values, " elements is ", complexity_heap_sort)
        #         number_of_current_values = int(number_of_current_values) * 2
        #         random_list = []
        #         copy_of_list = []
        #     number_of_current_values = number_of_values

        elif option == "0":
            break
        else:
            print("Invalid input")

main()