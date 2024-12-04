def has_common_digit(current_number: str, following_number: str) -> bool:
    digits_current_number = set(current_number)
    digits_following_number = set(following_number)
    if digits_current_number.intersection(digits_following_number):
        return 1
    else:
        return 0

def backtracking_increasing_subsets_with_common_digits(start, current_solution, subsets, last_selected, sequence):
    if len(current_solution) >= 2:
        subsets.append(current_solution)
    for i in range(start, len(sequence)):
        if (not current_solution or has_common_digit(str(current_solution[-1]), str(sequence[i]))) and (not current_solution or last_selected < sequence[i]):
            new_solution = current_solution + [sequence[i]]
            backtracking_increasing_subsets_with_common_digits(i + 1, new_solution, subsets, sequence[i], sequence)

def generate_increasing_subsets_with_common_digits(sequence):
    subsets = []
    backtracking_increasing_subsets_with_common_digits(0, [], subsets, -1, sequence)
    return subsets

def main():
    user_input = input("Insert a sequence of elements. ")
    elements_in_list = user_input.split()
    sequence = []
    for elements in elements_in_list:
        sequence.append(int(elements))
    sequence = [17, 21, 32, 5, 65, 6, 26, 15]
    result = generate_increasing_subsets_with_common_digits(sequence)
    for subset in result:
        print(subset)

main()