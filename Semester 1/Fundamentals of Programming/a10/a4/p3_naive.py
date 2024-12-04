def minimum_difference_of_the_sum_of_two_subsets(subset: list, index: int, sum_of_elements_first_subset: int,
                                                 sum_elements_second_subset: int, first_subset: list,
                                                 second_subset: list):
    if index < 0:
        current_difference = abs(sum_of_elements_first_subset - sum_elements_second_subset)
        return current_difference, first_subset, second_subset

    selected_items_first_subset_include = first_subset + [subset[index]]
    include_difference, include_result_first_subset, include_result_second_subset = minimum_difference_of_the_sum_of_two_subsets(
        subset, index - 1, sum_of_elements_first_subset + subset[index], sum_elements_second_subset,
        selected_items_first_subset_include, second_subset)

    selected_items2_exclude = second_subset + [subset[index]]
    exclude_difference, exclude_result_first_subset, exclude_result_second_subset = minimum_difference_of_the_sum_of_two_subsets(
        subset, index - 1, sum_of_elements_first_subset, sum_elements_second_subset + subset[index], first_subset,
        selected_items2_exclude)

    if include_difference < exclude_difference:
        return include_difference, include_result_first_subset, include_result_second_subset
    else:
        return exclude_difference, exclude_result_first_subset, exclude_result_second_subset


def main():
    # user_input = list(input("Insert a sequence of elements. "))
    user_input = [1, 2, 3, 4, 5]
    min_diff, subset1, subset2 = minimum_difference_of_the_sum_of_two_subsets(user_input, len(user_input) - 1, 0, 0, [],
                                                                              [])
    print('The minimum difference is', min_diff)
    print('Subset 1:', subset1)
    print('Subset 2:', subset2)


main()
