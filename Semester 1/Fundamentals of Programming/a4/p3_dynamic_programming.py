def minimum_difference_of_the_sum_of_two_subsets(given_set):
    length = len(given_set)
    total_sum = sum(given_set)
    maximum_sum_of_subset = total_sum
    dynamic_programming = [[False for i in range(maximum_sum_of_subset + 1)] for j in range(length)]

    for row in range(length):
        dynamic_programming[row][0] = True
        if given_set[row] <= maximum_sum_of_subset:
            dynamic_programming[row][given_set[row]] = True

    for index in range(1, length):
        for target_sum in range(1, maximum_sum_of_subset + 1):
            exclude_value = dynamic_programming[index - 1][target_sum]
            include_value = False

            if given_set[index] <= target_sum:
                include_value = dynamic_programming[index - 1][target_sum - given_set[index]]

            dynamic_programming[index][target_sum] = include_value or exclude_value

    minimum = float('inf')
    current_minimum_sum = -1

    for partial_sum in range(total_sum // 2 + 1):
        if dynamic_programming[length - 1][partial_sum]:
            if abs((total_sum - partial_sum) - partial_sum) < minimum:
                minimum = abs((total_sum - partial_sum) - partial_sum)
                current_minimum_sum = partial_sum

    first_subset = []
    second_subset = []
    index = length - 1
    target_sum = current_minimum_sum

    while index >= 0 and target_sum > 0:
        if index > 0 and dynamic_programming[index - 1][target_sum]:
            first_subset.append(given_set[index])
        else:
            second_subset.append(given_set[index])
            target_sum -= given_set[index]
        index -= 1

    for row in range (0, length):
        for columns in range (0, length):
            print(dynamic_programming[row][columns], end = " ")
        print ()
    return first_subset, second_subset

def main():
    #user_input = list(input("Insert a sequence of elements. "))
    subset = [1, 2, 3, 4, 5]
    first_subset, second_subset = minimum_difference_of_the_sum_of_two_subsets(subset)
    print("Subset 1:", first_subset)
    print("Subset 2:", second_subset)

main()