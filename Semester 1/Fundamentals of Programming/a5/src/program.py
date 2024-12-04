#
# Write the implementation for A5 in this file
#
from random import randint
# 
# Write below this comment 
# Functions to deal with complex numbers -- list representation
# -> There should be no print or input statements in this section 
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#

# def create_complex_number(real_part, imaginary_part):
#     return [real_part, imaginary_part]
#
# def generate_ten_random_complex_numbers(random_list_of_complex_numbers):
#     for i in range(10):
#         random_list_of_complex_numbers.append(create_complex_number(randint(-10, 10), randint(-10, 10)))
#     return random_list_of_complex_numbers
#
# def get_real_part(complex_number):
#     return complex_number[0]
#
# def set_real_part(complex_number, new_real_part):
#     complex_number[0] = new_real_part
#
# def get_imaginary_part(complex_number):
#     return complex_number[1]
#
# def set_imaginary_part(complex_number, new_imaginary_part):
#     complex_number[1] = new_imaginary_part
#
# def transform_complex_number_to_str_representation(complex_number):
#     return f"{complex_number[0]} + {complex_number[1]}i"


#
# Write below this comment 
# Functions to deal with complex numbers -- dict representation
# -> There should be no print or input statements in this section 
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#
def create_complex_number(real_part, imaginary_part):
    return {"real_part": real_part, "imaginary_part": imaginary_part}

def generate_ten_random_complex_numbers(random_list_of_complex_numbers):
    for i in range(10):
        random_list_of_complex_numbers.append(create_complex_number(randint(-10, 10), randint(-10, 10)))
    return random_list_of_complex_numbers

def get_real_part(complex_number):
    return complex_number["real_part"]

def get_imaginary_part(complex_number):
    return complex_number["imaginary_part"]

def transform_complex_number_to_string_representation(complex_number):
    return f"{complex_number['real_part']} + {complex_number['imaginary_part']}i"

#
# Write below this comment 
# Functions that deal with subarray/subsequence properties
# -> There should be no print or input statements in this section 
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#

def calculate_modulus(complex_number):
    return get_real_part(complex_number)**2 + get_imaginary_part(complex_number)**2

def longest_subarray_of_numbers_that_contain_at_most_three_distinct_values(current_complex_number_list):
    length_max_subarray = 0
    unique_values = []
    current_list_of_elements = []
    list_of_elements_with_a_maximum_of_three_distinct_values = []

    for i in range(0, len(current_complex_number_list)):
        for j in range(i, len(current_complex_number_list)):
            if calculate_modulus(current_complex_number_list[j]) in unique_values:
                current_list_of_elements.append(current_complex_number_list[j])
            else:
                if len(unique_values) < 3:
                    unique_values.append(calculate_modulus(current_complex_number_list[j]))
                    current_list_of_elements.append(current_complex_number_list[j])
                else:
                    if (length_max_subarray < len(current_list_of_elements)):
                        length_max_subarray = len(current_list_of_elements)
                        list_of_elements_with_a_maximum_of_three_distinct_values = current_list_of_elements
                    unique_values = []
                    current_list_of_elements = []
                    break

    return list_of_elements_with_a_maximum_of_three_distinct_values


def longest_alternating_subsequence_when_considering_the_real_part(current_complex_number_list):
    list_length = len(current_complex_number_list)
    dynamic_programming_matrix = [[[], []] for _ in range(list_length)]

    for i in range(list_length):
        current_complex_number = current_complex_number_list[i]
        dynamic_programming_matrix[i][0].append(current_complex_number)
        dynamic_programming_matrix[i][1].append(current_complex_number)

    for i in range(1, list_length):
        for j in range(i):
            current_complex_number_i = current_complex_number_list[i]
            current_complex_number_j = current_complex_number_list[j]

            if get_real_part(current_complex_number_j) < get_real_part(current_complex_number_i) and len(
                    dynamic_programming_matrix[i][0]) < len(dynamic_programming_matrix[j][1]) + 1:
                dynamic_programming_matrix[i][0] = dynamic_programming_matrix[j][1] + [current_complex_number_i]

            if get_real_part(current_complex_number_j) > get_real_part(current_complex_number_i) and len(
                    dynamic_programming_matrix[i][1]) < len(dynamic_programming_matrix[j][0]) + 1:
                dynamic_programming_matrix[i][1] = dynamic_programming_matrix[j][0] + [current_complex_number_i]
    longest_subsequence = []
    for i in range(list_length):
        if len(longest_subsequence) < len(dynamic_programming_matrix[i][0]):
            longest_subsequence = dynamic_programming_matrix[i][0]
        if len(longest_subsequence) < len(dynamic_programming_matrix[i][1]):
            longest_subsequence = dynamic_programming_matrix[i][1]

    return longest_subsequence


# Write below this comment 
# UI section
# Write all functions that have input or print statements here
# Ideally, this section should not contain any calculations relevant to program functionalities
#
def read_complex_number_from_the_console():
    real_part = int(input("Enter the real part: "))
    imaginary_part = int(input("Enter the imaginary part: "))
    return create_complex_number(real_part, imaginary_part)

def print_current_complex_number_list(current_complex_number_list):
    if not current_complex_number_list:
        print("Please enter some complex numbers first.")
    else:
        for current_complex_number in current_complex_number_list:
            print(transform_complex_number_to_string_representation(current_complex_number))

def main():
    # current_complex_number_list = [[7,1], [2,0], [3,0], [4,0], [2,0], [3,0], [5,0]]
    current_complex_number_list = [
        {'real_part': 7, 'imaginary_part': 1},
        {'real_part': 2, 'imaginary_part': 0},
        {'real_part': 3, 'imaginary_part': 0},
        {'real_part': 4, 'imaginary_part': 0},
        {'real_part': 2, 'imaginary_part': 0},
        {'real_part': 3, 'imaginary_part': 0},
        {'real_part': 5, 'imaginary_part': 0},
    ]
    # current_complex_number_list = []
    # generate_ten_random_complex_numbers(current_complex_number_list)
    print("1. Read a complex number")
    print("2. Display the current list of complex numbers")
    print("3. Display the length and elements of a longest subarray of numbers that contain at most 3 distinct values.")
    print("4. Display the length and elements of a longest alternating subsequence, when considering each number's real part")

    option_add_complex_number = 1
    option_display_complex_number_list = 2
    option_longest_subarray = 3
    option_longest_alternating_subsequence = 4

    while True:
        user_option = int(input("Choose an option. "))
        if user_option == option_add_complex_number:
            current_complex_number_list.append(read_complex_number_from_the_console())
        elif user_option == option_display_complex_number_list:
            print_current_complex_number_list(current_complex_number_list)
        elif user_option == option_longest_subarray:
            longest_subarray = longest_subarray_of_numbers_that_contain_at_most_three_distinct_values(current_complex_number_list)
            print ("The longest subarray of numbers that contain a maximum of three distinct values has ", len(longest_subarray), " elements:")
            print_current_complex_number_list(longest_subarray)
        elif user_option == option_longest_alternating_subsequence:
            longest_subsequence = longest_alternating_subsequence_when_considering_the_real_part(current_complex_number_list)
            print("The longest alternating subsequence, when considering each number's real part has", len(longest_subsequence), " elements:")
            print_current_complex_number_list(longest_subsequence)
        else:
            return 0

main()




