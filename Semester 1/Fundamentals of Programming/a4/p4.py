def backtracking_options_for_four_games(options, current_options):
    if len(current_options) == 4:
        print(current_options)
        return

    if len(current_options) == 4:
        return

    for i in range(0, len(options)):
        if (current_options.count('1') >= 2 and options[i] == '1') or (len(current_options) == 3 and options[i] == 'X'):
            continue
        current_options.append(options[i])
        backtracking_options_for_four_games(options, current_options)
        current_options.pop()

def main():
    options = ['1', 'X', '2']
    backtracking_options_for_four_games(options, [])

main()

# def backtracking_options_for_four_games(options, current_options):
#     # Check if the current combination has 4 options
#     if len(current_options) == 4:
#         print(current_options)
#         return
#
#     for option in options:
#         # If the option is '1', check if it exceeds the limit of two '1's
#         if option == '1' and current_options.count('1') >= 2:
#             continue
#
#         # If the combination has 3 options already, and the current option is 'X', skip it
#         if len(current_options) == 3 and option == 'X':
#             continue
#
#         # Add the option and continue the backtracking process
#         current_options.append(option)
#         backtracking_options_for_four_games(options, current_options)
#         current_options.pop()
#
# def main():
#     options = ['1', 'X', '2']
#     backtracking_options_for_four_games(options, [])
#
# main()