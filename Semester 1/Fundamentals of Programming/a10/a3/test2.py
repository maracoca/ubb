from random import randint

def create_complex_number(real_part, imaginary_part):
    return [real_part, imaginary_part]

def generate_ten_random_complex_numbers(random_list_of_complex_numbers):
    for i in range(10):
        random_list_of_complex_numbers.append(create_complex_number(randint(-10, 10), randint(-10, 10)))
    return random_list_of_complex_numbers

def get_real_part(complex_number):
    return complex_number[0]

def set_real_part(complex_number, new_real_part):
    complex_number[0] = new_real_part

def get_imaginary_part(complex_number):
    return complex_number[1]

def set_imaginary_part(complex_number, new_imaginary_part):
    complex_number[1] = new_imaginary_part

def transform_complex_number_to_str_representation(complex_number):
    return f"{complex_number[0]} + {complex_number[1]}i"

def read_complex_number_from_the_console():
    real_part = int(input("Enter the real part: "))
    imaginary_part = int(input("Enter the imaginary part: "))
    return create_complex_number(real_part, imaginary_part)

def print_current_complex_number_list(current_complex_number_list):
    if not current_complex_number_list:
        print("Please enter some complex numbers first.")
    else:
        for current_complex_number in current_complex_number_list:
            print(transform_complex_number_to_str_representation(current_complex_number))

# ... (previous code)

# def Max(a, b):
#     if a > b:
#         return a
#     else:
#         return b

# Function to return longest alternating
# subsequence length


# def longest_alternating_subsequence_when_considering_the_real_part(current_complex_number_list, list_length):
#     dynamic_programming_matrix = [[0 for i in range(2)]
#            for j in range(list_length)]
#
#     for i in range(list_length):
#         dynamic_programming_matrix[i][0], dynamic_programming_matrix[i][1] = 1, 1
#
#     longest_alternating_subsequence_length = 1
#
#     for i in range(1, list_length):
#         for j in range(0, i):
#             if (get_real_part(current_complex_number_list[j]) < get_real_part(current_complex_number_list[i]) and
#                     dynamic_programming_matrix[i][0] < dynamic_programming_matrix[j][1] + 1):
#                 dynamic_programming_matrix[i][0] = dynamic_programming_matrix[j][1] + 1
#                 #dp_direction = 1
#             if (get_real_part(current_complex_number_list[j]) > get_real_part(current_complex_number_list[i]) and
#                     dynamic_programming_matrix[i][1] < dynamic_programming_matrix[j][0] + 1):
#                 dynamic_programming_matrix[i][1] = dynamic_programming_matrix[j][0] + 1
#                 #dp_direction = -1
#
#         if (longest_alternating_subsequence_length < max(dynamic_programming_matrix[i][0], dynamic_programming_matrix[i][1])):
#             longest_alternating_subsequence_length = max(dynamic_programming_matrix[i][0], dynamic_programming_matrix[i][1])
#             #max_length_index = i
#     return longest_alternating_subsequence_length
#         # result = []
#         # current_direction = dp_direction[max_length_index]
#         #
#         # for i in range(max_length_index, -1, -1):
#         #     if dp_direction[i] == current_direction:
#         #         result.append(current_complex_number_list[i])
#         #         current_direction *= -1  # Switch direction
#         #
#         # # Reverse the result to get the correct order
#         # result = result[::-1]
#         #
#         # return result