#
# The program's functions are implemented here. There is no user interaction in this file, therefore no input/print statements. Functions here
# communicate via function parameters, the return statement and raising of exceptions. 
#
from random import randint
import random
from datetime import datetime
from copy import deepcopy


def generate_random_bank_transactions():
    list_of_bank_transactions = []
    for i in range(10):
        transaction_type = random.choice(['in', 'out'])
        if transaction_type == 'in':
            description = 'salary'
        else:
            description = random.choice(['food', 'clothes', 'taxes', 'leisure time'])

        bank_transaction = {
            'day': randint(1, 30),
            'amount': randint(0, 1000),
            'type': transaction_type,
            'description': description
        }
        list_of_bank_transactions.append(bank_transaction)

    #print(list_of_bank_transactions)
    return list_of_bank_transactions

def syntax_error():
    print("Your option is invalid. ")

def days_error():
    print("You can't have a month that has days outside the interval from 1 to 30. ")

def description_not_correct_error():
    print("Girl math! You can only make money from your salary. ")

def remove_error():
    print("You cannot remove something that does not exist. ")

def add_a_transaction(transaction_to_be_added, list_of_transactions):
    operation_index = 0
    amount = 1
    type = 2
    description = 3
    instruction_length = 4

    if len(transaction_to_be_added) == instruction_length:
        try:
            if transaction_to_be_added[type] == 'in':
                if transaction_to_be_added[description] != 'salary':
                    raise ValueError
        except ValueError:
            description_not_correct_error()

    try:
        if len(transaction_to_be_added) != instruction_length or not int(transaction_to_be_added[amount]) or (transaction_to_be_added[type] != 'in' and transaction_to_be_added[type] != 'out'):
           raise ValueError

        else:
            current_date = datetime.now()
            current_day = current_date.day
            new_transaction = {'day': current_day,
                               'amount': int(transaction_to_be_added[amount]),
                               'type': transaction_to_be_added[type],
                               'description': transaction_to_be_added[description]
                               }
            list_of_transactions.append(new_transaction)
    except ValueError:
        syntax_error()


def insert_a_transaction(transaction_to_be_inserted, list_of_transactions):
    day = 1
    amount = 2
    type = 3
    description = 4

    try:
        if int(transaction_to_be_inserted[day]) < 1 or int(transaction_to_be_inserted[day]) > 30:
            raise ValueError
    except ValueError:
        days_error()

    try:
        if transaction_to_be_inserted[type] == 'in':
            if transaction_to_be_inserted[description] != 'salary':
                raise ValueError
    except ValueError:
        description_not_correct_error()

    try:
        if not int(transaction_to_be_inserted[day]) or not int(transaction_to_be_inserted[amount]) or (transaction_to_be_inserted[type] != 'in' and transaction_to_be_inserted[type] != 'out'):
            raise ValueError

        else:
            new_transaction = {'day': int(transaction_to_be_inserted[day]),
                               'amount': int(transaction_to_be_inserted[amount]),
                               'type': transaction_to_be_inserted[type],
                               'description': transaction_to_be_inserted[description]
            }
            list_of_transactions.append(new_transaction)

    except ValueError:
        syntax_error()

def remove_all_transactions_from_a_day(day_to_be_removed, list_of_transactions):
    day = 1
    operation_index = 0

    try:
        if int(day_to_be_removed[day]) < 1 or int(day_to_be_removed[day]) > 30:
            raise ValueError
    except ValueError:
        days_error()

    try:
        if day_to_be_removed[operation_index] != 'remove':
            raise ValueError
    except ValueError:
        syntax_error()

    new_list_of_transactions = list_of_transactions.copy()
    for i in range(len(list_of_transactions)):
        if int(day_to_be_removed[day]) == get_day(list_of_transactions[i]):
            new_list_of_transactions.remove(new_list_of_transactions[i])

    try:
        if len(new_list_of_transactions) == len(list_of_transactions):
            raise ValueError
    except ValueError:
        remove_error()

    list_of_transactions = new_list_of_transactions
    return list_of_transactions
    #print(list_of_transactions)


def remove_all_transactions_between_two_days(days_to_be_removed, list_of_transactions):
    operation_index = 0
    starting_day = 1
    ending_day = 3

    try:
        if int(days_to_be_removed[starting_day]) < 1 or int(days_to_be_removed[starting_day]) > 30:
            raise ValueError
        elif int(days_to_be_removed[ending_day]) < 1 or int(days_to_be_removed[ending_day]) > 30:
            raise ValueError
    except ValueError:
        days_error()

    try:
        if days_to_be_removed[operation_index] != 'remove':
            raise ValueError
    except ValueError:
        syntax_error()


    new_list_of_transactions = list_of_transactions.copy()
    number_of_removals = 0
    for i in range(len(list_of_transactions)):
        if (int(days_to_be_removed[starting_day]) <= get_day(list_of_transactions[i])) and (int(days_to_be_removed[ending_day]) >= get_day(list_of_transactions[i])):
            new_list_of_transactions.remove(new_list_of_transactions[i - number_of_removals])
            number_of_removals += 1

    try:
        if len(new_list_of_transactions) == len(list_of_transactions):
            raise ValueError
    except ValueError:
        remove_error()

    list_of_transactions = new_list_of_transactions
    return list_of_transactions
    #print(new_list_of_transactions)

def remove_all_in_transactions(type, list_of_transactions):
    new_list_of_transactions = list_of_transactions.copy()
    number_of_removals = 0
    for i in range(len(list_of_transactions)):
        if get_type(list_of_transactions[i]) == 'in':
            new_list_of_transactions.remove(new_list_of_transactions[i - number_of_removals])
            number_of_removals += 1

    try:
        if len(new_list_of_transactions) == len(list_of_transactions):
            raise ValueError
    except ValueError:
        remove_error()

    list_of_transactions = new_list_of_transactions
    return list_of_transactions
    #print(new_list_of_transactions)

def remove_all_out_transactions(type, list_of_transactions):
    new_list_of_transactions = list_of_transactions.copy()
    number_of_removals = 0
    for i in range(len(list_of_transactions)):
        if get_type(list_of_transactions[i]) == 'out':
            new_list_of_transactions.remove(new_list_of_transactions[i - number_of_removals])
            number_of_removals += 1

    try:
        if len(new_list_of_transactions) == len(list_of_transactions):
            raise ValueError
    except ValueError:
        remove_error()

    list_of_transactions = new_list_of_transactions
    return list_of_transactions
    #print(new_list_of_transactions)


def replace_amount_in_given_transaction(transaction_to_be_replaced , list_of_transactions):
    day = 1
    type = 2
    description = 3
    replace_with = 4
    amount = 5

    try:
        if not int(transaction_to_be_replaced[day]) or (transaction_to_be_replaced[type] != 'in' and transaction_to_be_replaced[type] != 'out') or transaction_to_be_replaced[replace_with] != 'with' or not int(transaction_to_be_replaced[amount]):
            raise ValueError
        else:
            try:
                for i in range(len(list_of_transactions)):
                    if int(transaction_to_be_replaced[day]) == get_day(list_of_transactions[i]) and transaction_to_be_replaced[type] == get_type(list_of_transactions[i]) and transaction_to_be_replaced[description] == get_description(list_of_transactions[i]):
                        list_of_transactions[i] = { 'day': int(transaction_to_be_replaced[day]),
                                                    'amount': int(transaction_to_be_replaced[amount]),
                                                    'type': transaction_to_be_replaced[type],
                                                    'description': transaction_to_be_replaced[description]
                        }
                    else:
                        raise ValueError
            except ValueError:
                print("You cannot replace something that does not exist! ")
            #print(list_of_transactions)
    except ValueError:
        syntax_error()



def list_of_transactions_for_day(list_of_transactions, day):
    transactions_for_day = []
    for i in range(len(list_of_transactions)):
        if get_day(list_of_transactions[i]) == day:
            transactions_for_day.append(list_of_transactions[i])
    return transactions_for_day



def print_all_transactions(list_of_transactions):
    list_of_days = []
    for i in range(len(list_of_transactions)):
        if get_day(list_of_transactions[i]) not in list_of_days:
            transactions_for_day = list_of_transactions_for_day(list_of_transactions, get_day(list_of_transactions[i]))
            list_of_days.append(get_day(list_of_transactions[i]))
            print("The transactions for day ", get_day(list_of_transactions[i]), " are:")
            for j in range(len(transactions_for_day)):
               print("amount: ", get_amount(transactions_for_day[j]), "RON")
               print("type: ", get_type(transactions_for_day[j]))
               print("description: ", get_description(transactions_for_day[j]))


def list_of_all_transactions_with_a_given_type_for_day(list_of_transactions, day, type):
    transactions_for_day = []
    for i in range(len(list_of_transactions)):
        if get_day(list_of_transactions[i]) == day and get_type(list_of_transactions[i]) == type:
            transactions_for_day.append(list_of_transactions[i])
    return transactions_for_day


def print_all_transactions_with_given_type(type, list_of_transactions):
    operation_type = 1

    try:
        if (type[operation_type] != 'in' and type[operation_type] != 'out'):
            raise ValueError
        else:
            print("All in transactions are:")
            for i in range(len(list_of_transactions)):
                if type[operation_type] == get_type(list_of_transactions[i]):
                    transactions_for_day = list_of_all_transactions_with_a_given_type_for_day(list_of_transactions, get_day(list_of_transactions[i]), type[operation_type])
                    print("For day ", get_day(list_of_transactions[i]), " :")
                    for j in range(len(transactions_for_day)):
                        print("amount: ", get_amount(transactions_for_day[j]), "RON")
                        print("type: ", get_type(transactions_for_day[j]))
                        print("description: ", get_description(transactions_for_day[j]))
    except ValueError:
        syntax_error()


def list_of_all_transactions_equal_greater_or_lower_than_the_given_amount_for_day(list_of_transactions, day, symbol, amount):
    transactions_for_day = []
    for i in range(len(list_of_transactions)):
        if symbol == '=':
            if get_day(list_of_transactions[i]) == day and get_amount(list_of_transactions[i]) == amount:
                transactions_for_day.append(list_of_transactions[i])
        elif symbol == '>':
            if get_day(list_of_transactions[i]) == day and get_amount(list_of_transactions[i]) > amount:
                transactions_for_day.append(list_of_transactions[i])
        elif symbol == '<':
            if get_day(list_of_transactions[i]) == day and get_amount(list_of_transactions[i]) < amount:
                transactions_for_day.append(list_of_transactions[i])
    return transactions_for_day


def print_all_transactions_equal_with_amount(symbol_and_amount, list_of_transactions):
    amount = 2
    type = 1

    print("All transactions that contain ", symbol_and_amount[amount], " RON are:")
    for i in range(len(list_of_transactions)):
        if get_amount(list_of_transactions[i]) == int(symbol_and_amount[2]):
            transactions_for_day = list_of_all_transactions_equal_greater_or_lower_than_the_given_amount_for_day(list_of_transactions, get_day(list_of_transactions[i]), symbol_and_amount[type], int(symbol_and_amount[amount]))
            print("In day ", get_day(list_of_transactions[i]), ":")
            for j in range(len(transactions_for_day)):
                print("amount: ", get_amount(transactions_for_day[j]), "RON")
                print("type: ", get_type(transactions_for_day[j]))
                print("description: ", get_description(transactions_for_day[j]))


def print_all_transactions_greater_than_amount(symbol_and_amount, list_of_transactions):
    amount = 2
    type = 1

    print("All transactions that contain more than ", symbol_and_amount[amount], " RON are:")
    for i in range(len(list_of_transactions)):
        if int(symbol_and_amount[amount]) < get_amount(list_of_transactions[i]):
            transactions_for_day = list_of_all_transactions_equal_greater_or_lower_than_the_given_amount_for_day(list_of_transactions, get_day(list_of_transactions[i]), symbol_and_amount[type], int(symbol_and_amount[amount]))
            print("In day ", get_day(list_of_transactions[i]), ":")
            for j in range(len(transactions_for_day)):
                print("amount: ", get_amount(transactions_for_day[j]), "RON")
                print("type: ", get_type(transactions_for_day[j]))
                print("description: ", get_description(transactions_for_day[j]))


def print_all_transactions_lower_than_amount(symbol_and_amount, list_of_transactions):
    amount = 2
    type = 1

    print("All transactions that contain less than ", symbol_and_amount[amount], " RON are:")
    for i in range(len(list_of_transactions)):
        if int(symbol_and_amount[amount]) > get_amount(list_of_transactions[i]):
            transactions_for_day = list_of_all_transactions_equal_greater_or_lower_than_the_given_amount_for_day(list_of_transactions, get_day(list_of_transactions[i]), symbol_and_amount[type], int(symbol_and_amount[amount]))
            print("In day ", get_day(list_of_transactions[i]), ":")
            for j in range(len(transactions_for_day)):
                print("amount: ", get_amount(transactions_for_day[j]), "RON")
                print("type: ", get_type(transactions_for_day[j]))
                print("description: ", get_description(transactions_for_day[j]))


def account_balance_at_the_end_of_a_given_day(day, list_of_transactions):
    operation_day = 2

    try:
        if int(day[operation_day]) < 1 or int(day[operation_day]) > 30:
            raise ValueError

        else:
            account_balance = 0
            for i in range(len(list_of_transactions)):
                if get_day(list_of_transactions[i]) <= int(day[operation_day]):
                    if get_type(list_of_transactions[i]) == 'in':
                        account_balance += get_amount(list_of_transactions[i])
                    else:
                        account_balance -= get_amount(list_of_transactions[i])
            print("Your account balance is ", account_balance)
    except ValueError:
        days_error()


def filter_transactions_by_type(type, list_of_transactions):
    operation_type = 1

    new_list_of_transactions = list_of_transactions.copy()
    number_of_removals = 0
    for i in range(len(list_of_transactions)):
        if (get_type(list_of_transactions[i]) != type[operation_type]):
            new_list_of_transactions.remove(new_list_of_transactions[i - number_of_removals])
            number_of_removals += 1
    list_of_transactions = new_list_of_transactions
    # print(list_of_transactions)
    return list_of_transactions

def filter_transactions_by_type_and_amount(type_and_amount, list_of_transactions):
    type = 1
    amount = 2

    new_list_of_transactions = list_of_transactions.copy()
    number_of_removals = 0
    for i in range(len(list_of_transactions)):
        if (get_type(list_of_transactions[i]) != type_and_amount[type]):
            new_list_of_transactions.remove(new_list_of_transactions[i - number_of_removals])
            number_of_removals += 1
        elif (get_type(list_of_transactions[i]) == type_and_amount[type]) and (get_amount(list_of_transactions[i]) > int(type_and_amount[amount])):
            new_list_of_transactions.remove(new_list_of_transactions[i - number_of_removals])
            number_of_removals += 1
    list_of_transactions = new_list_of_transactions
    #print(list_of_transactions)
    return list_of_transactions

def update_history(list_of_transactions, history):
    history.append(deepcopy(list_of_transactions))
    return history

# def print_transaction(transaction):
#     return f"day {get_day(transaction)}, amount {get_amount(transaction)}, type {get_type(transaction)}, description {get_description(transaction)}"

def get_day(transaction):
    return transaction['day']

def get_amount(transaction):
    return transaction['amount']

def get_type(transaction):
    return transaction['type']

def get_description(transaction):
    return transaction['description']