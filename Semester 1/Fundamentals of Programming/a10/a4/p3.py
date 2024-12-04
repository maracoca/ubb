def backtracking_strictly_increasing_subsequences(start, current_subsequence, sequence):
    if current_subsequence:
        print(current_subsequence)

    for i in range(start, len(sequence)):
        if len(current_subsequence) == 0 or sequence[i] > current_subsequence[-1]:
            current_subsequence.append(sequence[i])
            backtracking_strictly_increasing_subsequences(i, current_subsequence, sequence)
            current_subsequence.pop()

def main():
    sequence = [3, 8, 2, 10, 5, 20]
    backtracking_strictly_increasing_subsequences(0, [], sequence)

main()
