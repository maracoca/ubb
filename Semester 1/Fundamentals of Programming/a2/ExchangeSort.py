from random import randint


def exchange_sort(unsorted: list, step: int):
    """
    Function that sorts a list with the Exchange Sort Algorithm
    :param unsorted: the randomly generated list that needs to be sorted
    :param step: how many swaps are being made before showing a partial list
    """
    list_size = len(unsorted)
    current_step = 0
    for i in range(0, list_size - 1):
        for j in range(i + 1, list_size):
            if unsorted[i] > unsorted[j]:
                unsorted[i], unsorted[j] = unsorted[j], unsorted[i]
                current_step += 1
                if current_step % step == 0:
                    print(unsorted)
    print("The sorted list is " + str(unsorted))


def heapify(unsorted: list, greatest_index: int, parent: int, step: int, current_step: int):
    """
    The conversion of the list into a max heap (the greatest element is on index 0 of the list)
    :param unsorted: randomly generated list
    :param greatest_index: the current greatest index that doesn't have the right value
    :param parent: the parent that needs to be compared with its children
    :param step: how many swaps are being made before showing a partial list
    :param current_step: the numbers of steps that have been made until now
    :return: current step that needs to be updated in the heap_sort function as well
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
        current_step += 1
        if current_step % step == 0:
            print(unsorted)
            #print('heapify ', current_step)
        current_step = heapify(unsorted, greatest_index, largest_number, step, current_step)
    return current_step


def heap_sort(unsorted: list, step: int):
    """
    The elimination of the highest element and the resulted max heap
    :param unsorted: randomly generated list
    :param step: how many swaps are being made before showing a partial list
    """
    current_step = 0
    list_lenght = len(unsorted)
    for i in range(list_lenght // 2 - 1, -1, -1):
        current_step = heapify(unsorted, list_lenght, i, step, current_step)
        #print(current_step)
    for i in range(list_lenght - 1, 0, -1):
        unsorted[i], unsorted[0] = unsorted[0], unsorted[i]
        current_step += 1
        if current_step % step == 0:
            print(unsorted)
            #print('main ', current_step)
        current_step = heapify(unsorted, i, 0, step, current_step)
    print("The sorted list is " + str(unsorted))


def main():
    random_list = []
    while True:
        print("1. Generate a list of n random natural numbers. ")
        print("2. Sort the list using the ExchangeSort algorithm. ")
        print("3. Sort the list using the HeapSort algorithm. ")
        print("0. Exit the program")
        option = input("Choose a number ")

        if option == "1":
            random_list = []
            number_of_values = input("Choose how many numbers you want your list to have ")
            for i in range(1, int(number_of_values) + 1):
                values = randint(0, 100)
                random_list.append(values)
            print(random_list)
        elif option == "2":
            if random_list == []:
                print("Please generate a list first")
            else:
                step = int(input("How many steps do you want to see each time? "))
                exchange_sort(random_list, step)
        elif option == "3":
            if random_list == []:
                print("Please generate a list first")
            else:
                step = int(input("How many steps do you want to see each time? "))
                heap_sort(random_list, step)
        elif option == "0":
            break
        else:
            print("Invalid input!")

main()
