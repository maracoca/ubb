from datetime import datetime, timedelta
from random import randint

from src.domain.book import Book, import_books
from src.domain.client import Client, import_clients


class Rental():
    def __init__(self, id, book_id, client_id, rented_day, returned_day):
        self._id = id
        self._book_id = book_id
        self._client_id = client_id
        self._rented_day = rented_day
        self._returned_day = returned_day


    @property
    def id(self):
        return self._id

    @property
    def book_id(self) -> str:
        return self._book_id

    @property
    def client_id(self) -> str:
        return self._client_id

    @property
    def rented_day(self):
        return self._rented_day

    @property
    def returned_day(self):
        return self._returned_day

    @returned_day.setter
    def returned_day(self, returned_day):
        self._returned_day = returned_day

    def __str__(self):
        return f"Rental id: {self.id}, book id: {self.book_id}, client id: {self.client_id}, rented date: {self.rented_day}, returned date: {self.returned_day}"

def import_rentals():
    rentals = []
    rental_id = 1
    books = import_books()
    clients = import_clients()
    for i in range(20):
        rented_day = datetime(2023, randint(1, 12), randint(1, 28), hour=randint(7, 18))
        rentals.append(Rental(rental_id, books[i].id, clients[randint(0, 19)].id, rented_day, rented_day + timedelta(days=randint(1, 31))))
        rental_id += 1
    return rentals