def has_common_digit(current_number: str, following_number: str) -> bool:
    digits_current_number = set(current_number)
    digits_following_number = set(following_number)
    if digits_current_number.intersection(digits_following_number):
        return 1
    else:
        return 0

def generate_all_subsets_of_the_given_sequence(sequence):
    all_subsets = [[]]
    for element in sequence:
        subsets_up_to_the_current_element = []
        for subset in all_subsets:
            updated_subsets = subset + [element]
            subsets_up_to_the_current_element.append(updated_subsets)
        all_subsets.extend(subsets_up_to_the_current_element)
    return all_subsets

def is_increasing_subset_with_common_digits(subset):
    if len(subset) >= 2:
        for i in range(len(subset)):
            if i < len(subset) - 1 and subset[i] > subset[i + 1]:
                return 0
            if i >= 1:
                if has_common_digit(str(subset[i - 1]), str(subset[i])) == 0:
                    return 0
        return 1
    else:
        return 0

def main():
    user_input = input("Insert a sequence of elements. ")
    elements_in_list = user_input.split()
    sequence = []
    for elements in elements_in_list:
        sequence.append(int(elements))
    #sequence = [17, 21, 32, 5, 65, 6, 26, 15]
    subsets = generate_all_subsets_of_the_given_sequence(sequence)
    for subset in subsets:
        if is_increasing_subset_with_common_digits(subset):
            print(subset)

main()