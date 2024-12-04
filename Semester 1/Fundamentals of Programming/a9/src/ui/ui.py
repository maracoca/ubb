from src.domain.book import Book
from src.domain.client import Client
from src.repository.BinaryRepository import BinaryBookRepository, BinaryClientRepository, BinaryRentalRepository
from src.repository.TextFileRepository import TextBookRepository, TextClientRepository, TextRentalRepository
from src.repository.MemoryRepository import MemoryRepository, RepositoryError
from src.services.book_services import BookService
from src.services.client_services import ClientService
from src.services.rental_services import RentalService

class UI():
    def __init__(self, book_service, client_service, rental_service, undo_redo_service):
        # self.book_service = book_service
        # self.client_service = client_service
        # self.rental_service =rental_service

        self.book_service = book_service
        self.client_service = client_service
        self.rental_service = rental_service
        self.undo_redo_service = undo_redo_service

        # book_repository = MemoryRepository()
        # book_repository = TextBookRepository()
        # book_repository = BinaryBookRepository()
        # self.book_service = BookService(book_repository)
        # client_repository = MemoryRepository()
        # client_repository = TextClientRepository()
        # client_repository = BinaryClientRepository()
        # self.client_service = ClientService(client_repository)
        # # rental_repository = MemoryRepository()
        # # rental_repository = TextRentalRepository()
        # rental_repository = BinaryRentalRepository()
        # self.rental_service = RentalService(self.book_service.repository, self.client_service.repository, book_repository, client_repository, rental_repository)
    def program_start(self):
        manage_clients_and_books = "1"
        rent_and_return_books = "2"
        search = "3"
        statistics = "4"
        undo_redo = "5"
        exit = "6"

        while True:
            print("Select the desired command: ")
            print("1. Manage clients and books.")
            print("2. Rent and return books.")
            print("3. Search with criteria.")
            print("4. Present statistics.")
            print("5. Perform an undo/redo.")
            print("6. Exit the program.")

            command = input(">")
            if command == manage_clients_and_books:
                self.manage_clients_and_books()
            elif command == rent_and_return_books:
                self.rent_and_return_books()
            elif command == search:
                self.search()
            elif command == statistics:
                self.statistics()
            elif command == undo_redo:
                self.undo_redo()
            elif command == exit:
                break
            else:
                print("Invalid command.")

    def manage_clients_and_books(self):
        add_book = "1"
        remove_book = "2"
        update_book = "3"
        list_books = "4"
        add_client = "5"
        remove_client = "6"
        update_clients = "7"
        list_clients = "8"
        back = "9"

        while True:
            print("What do you want to do next? ")
            print("1. Add a new book.")
            print("2. Remove a book.")
            print("3. Update a book.")
            print("4. Show all books.")
            print("5. Add a new client.")
            print("6. Remove a client.")
            print("7. Update a client.")
            print("8. Show all clients.")
            print("9. Go back.")

            user_input = input(">")
            if user_input == add_book:
                try:
                    book_id = int(input("Enter book ID: "))
                    title = input("Enter title: ")
                    author = input("Enter author: ")
                    self.book_service.add_books(book_id, title, author)
                except RepositoryError as error:
                    print(error)

            elif user_input == remove_book:
                try:
                    book_id = int(input("Enter book ID: "))
                    self.book_service.remove_books(book_id)
                except RepositoryError as error:
                    print(error)

            elif user_input == update_book:
                try:
                    book_id = int(input("Enter book ID: "))
                    title = input("Enter title: ")
                    author = input("Enter author: ")
                    book = Book(book_id, title, author)
                    self.book_service.update(book)
                except RepositoryError as error:
                    print(error)

            elif user_input == list_books:
                books = self.book_service.get_all_books()
                for book in books:
                    print(book)

            elif user_input == add_client:
                try:
                    client_id = int(input("Enter client ID: "))
                    name = input("Enter name: ")
                    self.client_service.add_clients(client_id, name)
                except RepositoryError as error:
                    print(error)

            elif user_input == remove_client:
                try:
                    client_id = int(input("Enter client ID: "))
                    self.client_service.remove_clients(client_id)
                except RepositoryError as error:
                    print(error)

            elif user_input == update_clients:
                try:
                    client_id = int(input("Enter client ID: "))
                    name = input("Enter name: ")
                    client = Client(client_id, name)
                    self.client_service.update(client)
                except RepositoryError as error:
                    print(error)

            elif user_input == list_clients:
                clients = self.client_service.get_all_clients()
                for client in clients:
                    print(client)

            elif user_input == back:
                break
                
            else:
                print("Invalid command.")


    def rent_and_return_books(self):
        rent_book = "1"
        return_book = "2"
        back = "3"

        while True:
            print("What do you want to do next? ")
            print("1. Rent a book.")
            print("2. Return a book.")
            print("3. Go back.")

            user_input = input(">")

            if user_input == rent_book:
                try:
                    book_id = int(input("Enter book ID: "))
                    client_id = int(input("Enter client ID: "))

                #books = self.book_service.get_all_books()
                #clients = self.client_service.get_all_clients()

                    self.rental_service.rent_book(book_id, client_id)
                except RepositoryError as error:
                    print(error)

            elif user_input == return_book:
                rental_id = int(input("Enter your rental ID: "))
                # return_day = input("Enter return day: ")
                self.rental_service.return_book(rental_id)

            elif user_input == back:
                break

            else:
                print("Invalid command.")

    def search(self):
        search_client = "1"
        search_id = "2"
        search_title = "3"
        search_author = "4"
        back = "5"

        while True:
            print("What do you want search? ")
            print("1. Search client by name.")
            print("2. Search book by id.")
            print("3. Search book by title.")
            print("4. Search book by author.")
            print("5. Go back.")

            user_input = input(">")

            if user_input == search_client:
                try:
                    client_name = input("Enter name: ")
                    clients = self.client_service.find_name(client_name)
                    for client in clients:
                        print(client)
                except RepositoryError as error:
                    print(error)

            elif user_input == search_id:
                try:
                    book_id = int(input("Enter book ID: "))
                    book = self.book_service.search_id(book_id)
                    print(book)
                except RepositoryError as error:
                    print(error)

            elif user_input == search_title:
                try:
                    book_title = input("Enter book title: ")
                    books = self.book_service.find_title(book_title)
                    for book in books:
                        print(book)
                except RepositoryError as error:
                    print(error)

            elif user_input == search_author:
                book_author = input("Enter book author: ")
                books = self.book_service.find_author(book_author)
                for book in books:
                    print(book)

            elif user_input == back:
                break

            else:
                print("Invalid command.")

    def statistics(self):
        most_rented = "1"
        most_active_clients = "2"
        most_rented_authors = "3"
        back = "4"

        while True:
            print("What statistics do you want to see? ")
            print("1. Most rented books.")
            print("2. Most active clients.")
            print("3.  Most rented authors.")
            print("4. Go back.")

            user_input = input(">")
            if user_input == most_rented:
                most_rented_books_list = self.rental_service.most_rented_books()
                # for books in most_rented_books_list:
                #     print(books)

            elif user_input == most_active_clients:
                self.rental_service.most_active_clients()

            elif user_input == most_rented_authors:
                self.rental_service.most_rented_author()

            elif user_input == back:
                break
            else:
                print("Invalid command.")

    def undo_redo(self):
        undo = "1"
        redo = "2"
        back = "3"

        while True:
            print("What would you like to do? ")
            print("1. Undo last operation.")
            print("2. Redo last operation.")
            print("3. Go back")

            user_input = input(">")
            if user_input == undo:
                self.undo_redo_service.undo()
                print("Undo done")
            elif user_input == redo:
                self.undo_redo_service.redo()
                print("Redo done")
            elif user_input == back:
                break
            else:
                print("Invalid command.")




# ui = UI()
# ui.program_start()