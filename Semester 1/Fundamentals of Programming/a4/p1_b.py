def backtrack(start, target, path, coins, result):
    if target == 0:
        result.append(path[:])
        return
    for i in range(start, len(coins)):
        if coins[i] <= target:
            path.append(coins[i])
            backtrack(i, target - coins[i], path, coins, result)
            path.pop()

def find_payment_modalities(coins, s):
    result = []
    backtrack(0, s, [], coins, result)
    return result


# Example usage
coins = [1, 2, 3, 4]
sum_value = 5
modalities = find_payment_modalities(coins, sum_value)

if modalities:
    print(f"Payment modalities for sum {sum_value}: {modalities}")
else:
    print(f"No payment modality exists for sum {sum_value}.")
