def slope(p1, p2):
    if p1[0] == p2[0]:
        return float('inf')  # Vertical line, use infinity as slope
    return (p2[1] - p1[1]) / (p2[0] - p1[0])

# def are_collinear(p1, p2, p3):
#     # Check if three points are collinear
#     return slope(p1, p2) == slope(p2, p3)

def find_collinear_subsets(points, current_subset, index, list_of_slopes):
    if len(current_subset) >= 3:
        print(current_subset)
    for i in range(index, len(points)):
        if len(current_subset) >= 3:
            if slope(current_subset[-2], current_subset[-1]) != slope(current_subset[-1], points[i]):
                continue
        current_subset.append(points[i])
        # if len(current_subset) > 1:
        #     current_slope = slope(current_subset[-1], current_subset[-2])
        #     list_of_slopes.append(current_slope)

        # Recursively explore subsets
        find_collinear_subsets(points, current_subset, i + 1, list_of_slopes)

        # Backtrack
        current_subset.pop()

# Example usage:
points = [(1, 1), (2, 2), (3, 3), (1, 2), (2, 4), (3, 6)]
find_collinear_subsets(points, [], 0, [])

# if found:
#     print("Collinear subsets:")
#
# else:
#     print("No collinear subsets found.")
