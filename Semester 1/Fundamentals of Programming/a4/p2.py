# def is_prime(num):
#     prime_numbers = []
#     for i in range(2, num):
#         if num % i != 0:
#             prime_numbers.append(i)
#     return prime_numbers
#
#
# def backtrack(start, target, path, result):
#     if target == 0:
#         result.append(path[:])
#         return
#     for i in range(start, len(is_prime(target))):
#         if is_prime(target)[i] <= target:
#             path.append(is_prime(target)[i])
#             backtrack(i, target - is_prime(target)[i], path, result)
#             path.pop()
#
# def decompose_as_primes(n):
#     result = []
#     backtrack(0, n, [], result)
#     return result
#
# # Example usage
# number_to_decompose = 8
# decompositions = decompose_as_primes(number_to_decompose)
#
# if decompositions:
#     print(f"Decompositions of {number_to_decompose} as sums of prime numbers:")
#     for decomposition in decompositions:
#         print(decomposition)
# else:
#     print(f"No decompositions exist for {number_to_decompose}.")

def is_prime(num):
    if num < 2:
        return False
    for i in range(2, num // 2):
        if num % i == 0:
            return False
    return True

def list_of_prime_numbers(n):
    prime_numbers=[]
    for i in range (2, n+1):
        if is_prime(i):
            prime_numbers.append(i)
    return prime_numbers

def backtrack(start, target, path, primes, result):
    if target == 0:
        result.append(path[:])
        return
    for i in range(start, len(primes)):
        if primes[i] <= target:
            path.append(primes[i])
            backtrack(i, target - primes[i], path, primes, result)
            path.pop()

def decompose_as_primes(n):
    result = []
    prime_numbers = list_of_prime_numbers(n)
    backtrack(0, n, [], prime_numbers, result)
    return result

# Example usage
number_to_decompose = 10
decompositions = decompose_as_primes(number_to_decompose)

if decompositions:
    print(f"Decompositions of {number_to_decompose} as sums of prime numbers:")
    for decomposition in decompositions:
        print(decomposition)
else:
    print(f"No decompositions exist for {number_to_decompose}.")
