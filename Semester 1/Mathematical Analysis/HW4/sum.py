def sum_of_positive_terms(p: int, sum: int, term: int):
    for i in range(1, p+1):
        sum = sum + (-1) / term
        term += 2
    return sum

def sum_of_negative_terms(q: int, sum: int, term: int):
    for i in range(1, q + 1):
        sum = sum + 1 / term
        term += 2
    return sum

number_of_sums = int(input("How many sums would you like to calculate? "))
while number_of_sums:
    number_of_elements = int(input("How much would you like n to be? "))
    p = int(input("How many positive elements would you like to add? "))
    q = int(input("How many negative elements would you like to add? "))
    sum_of_current_elements = 0
    index_p = 2
    index_q = 1
    while index_p < number_of_elements and index_q < number_of_elements and index_p + index_q < number_of_elements:
        sum_of_current_elements = sum_of_current_elements + sum_of_positive_terms(p, 0, index_p) + sum_of_negative_terms(q, 0, index_q)
        index_p += p
        index_q += q

    number_of_sums -= 1
    print(sum_of_current_elements)

