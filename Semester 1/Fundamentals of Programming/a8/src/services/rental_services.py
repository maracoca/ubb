from datetime import datetime, timedelta
from random import randint

from src.domain.rental import Rental, import_rentals


class RentalService():
    def __init__(self, book: list, client: list, book_repository, client_repository, rental_repository):
        self.rental_repository = rental_repository
        self.book_repository = book_repository
        self.client_repository = client_repository
        self.book = book
        self.client = client
        self.rented_day = datetime(2023, randint(1, 12), randint(1, 28), hour=randint(7, 18))
        self.rental_counter = 21
        self.generate_rentals()

    def generate_rentals(self):
        rentals = import_rentals()
        for rental in rentals:
            self.rental_repository.add(rental)

    def rent_book(self, book_id, client_id):
        book = self.book_repository.find_by_id(book_id)
        client = self.client_repository.find_by_id(client_id)

        if book and client:
            if book.is_available:
                rental = Rental(self.rental_counter, book.id, client.id, self.rented_day, returned_day = None)
                self.rental_repository.add(rental)
                book.is_available = False
                print(f"Book rented to {client.name}: {book.title} by {book.author} on {self.rented_day}. Your rental id is: {self.rental_counter}")
                self.rented_day = self.rented_day + timedelta(days=randint(1, 31))
                self.rental_counter += 1
            else:
                print("Book is already rented.")
        else:
            print("Invalid book ID or client ID.")

    def return_book(self, rental):
        rental = self.rental_repository.find_by_id(int(rental))

        if rental:
            book_id = rental.book_id
            book = self.book_repository.find_by_id(book_id)
            book.is_available = True
            rented_day = rental.rented_day
            returned_day = rented_day + timedelta(days=randint(1, 31))
            rental.returned_day = returned_day
            print(f"Book with id {rental.book_id} was returned on {rental.returned_day}")
        else:
            print("Invalid rented_day ID.")

    def most_rented_books(self):
        rentals = self.rental_repository.get_all_objects()
        books = self.book_repository.get_all_objects()
        book_rentals = {}
        for book in books:
            book_id = book.id
            book_rentals[int(book_id)] = 0
        for rental in rentals:
            book_id = rental.book_id
            if int(book_id) in book_rentals.keys():
                book_rentals[int(book_id)] += 1
            else:
                book_rentals[int(book_id)] = 1
        sorted_books = sorted(book_rentals.items(), key=lambda x: x[1], reverse=True)
        for book in sorted_books:
            print(f"Book with id {book[0]} was rented {book[1]} times" )
        # return sorted_books

    def most_active_clients(self):
        rentals = self.rental_repository.get_all_objects()
        clients = self.client_repository.get_all_objects()
        client_rental_days = {}
        for client in clients:
            client_id = client.id
            client_rental_days[int(client_id)] = 0
        for rental in rentals:
            client_id = rental.client_id
            if rental.returned_day:
                client_rental_days[int(client_id)] += (rental.returned_day - rental.rented_day).days


        sorted_clients = sorted(client_rental_days.items(), key=lambda x: x[1], reverse=True)
        for client in sorted_clients:
            print(f"Client with id {client[0]} has a total of {client[1]} rental days")

    def most_rented_author(self):
        rentals = self.rental_repository.get_all_objects()
        books = self.book_repository.get_all_objects()
        author_rentals = {}
        for book in books:
            book_author = book.author
            author_rentals[book_author] = 0
        for rental in rentals:
            for book in books:
                if rental.book_id == book.id:
                    author_rentals[book.author] += 1

        sorted_authors = sorted(author_rentals.items(), key=lambda x: x[1], reverse=True)
        for author in sorted_authors:
            print(f"Books with author {author[0]} have been rented {author[1]} times.")



