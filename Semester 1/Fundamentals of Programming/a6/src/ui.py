#
# This is the program's UI module. The user interface and all interaction with the user (print and input statements) are found here
#

import functions
def user_input():
    history = []
    list_of_transactions = functions.generate_random_bank_transactions()
    history = functions.update_history(list_of_transactions, history)
    print("You can do the following: ")
    print("Add or insert a transaction. ")
    print("Remove all transactions from a day, all transactions from multiple days, all transactions with a given type, replace in transactions from a day. ")
    print("List all transactions, all transactions with a given type, all transactions that have an amount equal/lower/greater than a desired amount, the balance up to a desired day. ")
    print("Filter the transactions based on their type or their type and value. ")
    print("Undo your last command. ")
    print("Exit. ")

    operation_type = 0
    type = 1
    day_to_be_removed = 1
    symbol = 1
    amount = 2
    remove_interval_length = 4
    print_all = 1
    print_by_type = 2
    print_balance = 1
    filter_by_type = 2
    length_initial_list = 1

    while True:
        user_input = input("Choose what you want to do. ")
        splitted_user_choice = user_input.split()
        if splitted_user_choice[operation_type] == 'add':
            history = functions.update_history(list_of_transactions, history)
            functions.add_a_transaction(splitted_user_choice, list_of_transactions)
            # print(list_of_transactions)


        elif splitted_user_choice[operation_type] == 'insert':
            history = functions.update_history(list_of_transactions, history)
            functions.insert_a_transaction(splitted_user_choice, list_of_transactions)
            #print(list_of_transactions)

        elif splitted_user_choice[operation_type] == 'remove':

            try:
                if splitted_user_choice[type] != 'in' and splitted_user_choice[type] != 'out' and not int(splitted_user_choice[day_to_be_removed]):
                    raise ValueError

                elif splitted_user_choice[type] == 'in':
                    history = functions.update_history(list_of_transactions, history)
                    list_of_transactions = functions.remove_all_in_transactions(splitted_user_choice, list_of_transactions)

                elif splitted_user_choice[type] == 'out':
                    history = functions.update_history(list_of_transactions, history)
                    list_of_transactions = functions.remove_all_out_transactions(splitted_user_choice, list_of_transactions)

                elif len(splitted_user_choice) == remove_interval_length:
                    history = functions.update_history(list_of_transactions, history)
                    list_of_transactions = functions.remove_all_transactions_between_two_days(splitted_user_choice, list_of_transactions)

                else:
                    history = functions.update_history(list_of_transactions, history)
                    list_of_transactions = functions.remove_all_transactions_from_a_day(splitted_user_choice, list_of_transactions)
            except ValueError:
                print("Invalid input!")


        elif splitted_user_choice[operation_type] == 'replace':
            history = functions.update_history(list_of_transactions, history)
            functions.replace_amount_in_given_transaction(splitted_user_choice, list_of_transactions)

        elif splitted_user_choice[operation_type] == 'list':
            if len(splitted_user_choice) == print_all:
                functions.print_all_transactions(list_of_transactions)
            elif len(splitted_user_choice) == print_by_type:
                functions.print_all_transactions_with_given_type(splitted_user_choice, list_of_transactions)
            else:
                if splitted_user_choice[print_balance] == 'balance':
                    functions.account_balance_at_the_end_of_a_given_day(splitted_user_choice, list_of_transactions)
                else:
                    try:
                        if (splitted_user_choice[symbol] != '=' and splitted_user_choice[symbol] != '>' and splitted_user_choice[symbol] != '<') or not int(splitted_user_choice[amount]):
                            raise ValueError
                        elif splitted_user_choice[symbol] == '=':
                            functions.print_all_transactions_equal_with_amount(splitted_user_choice, list_of_transactions)
                        elif splitted_user_choice[symbol] == '>':
                            functions.print_all_transactions_greater_than_amount(splitted_user_choice, list_of_transactions)
                        elif splitted_user_choice[symbol] == '<':
                            functions.print_all_transactions_lower_than_amount(splitted_user_choice, list_of_transactions)
                    except ValueError:
                        print("Your input is invalid. ")

        elif splitted_user_choice[operation_type] == 'filter':
            try:
                if splitted_user_choice[type] != 'in' and splitted_user_choice[type] != 'out':
                    raise ValueError

                elif len(splitted_user_choice) == filter_by_type:
                    history = functions.update_history(list_of_transactions, history)
                    list_of_transactions = functions.filter_transactions_by_type(splitted_user_choice, list_of_transactions)
                else:
                    try:
                        if not int(splitted_user_choice[amount]):
                            raise ValueError
                        else:
                            history = functions.update_history(list_of_transactions, history)
                            list_of_transactions = functions.filter_transactions_by_type_and_amount(splitted_user_choice, list_of_transactions)
                    except ValueError:
                        print("Invalid input! ")
            except ValueError:
                print("Invalid input! ")

        elif splitted_user_choice[operation_type] == 'undo':
            if len(history) <= length_initial_list:
                print("List already in default state. ")
            else:
                list_of_transactions = history.pop()
                print("Undo successful.")

        elif splitted_user_choice[operation_type] == 'exit':
            exit()

        else:
            print("Invalid input! ")



