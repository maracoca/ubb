#
# This module is used to invoke the program's UI and start it. It should not contain a lot of code.
#
import ui

def main():
    ui.user_input()

main()

# days_dict = {
#     "2":
#     [
#         {
#             "amount": 10,
#             "type": "in"
#             "object": "salary"
#         },
#         {
#             "amount": 29,
#             "type": "out",
#             "object": "clothes"
#         },
#     ],
#     "3":
#     [
#         {
#             "amount": 29,
#             "type": "out",
#             "object": "clothes"
#         },
#     ]
# }
# print(days_dict['2'][1]['amount'])
#
# for day, transactions in days_dict.items():
#     for trans in transactions:
#         print(day, trans)
