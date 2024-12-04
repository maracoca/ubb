import unittest

from src.domain.book import Book
from src.domain.client import Client
from src.repository.memory_repository import MemoryRepository
from src.services.book_services import BookService
from src.services.client_services import ClientService


class TestMemory(unittest.TestCase):
    def setUp(self):
        book_repository = MemoryRepository()
        self.book = BookService(book_repository)
        client_repository = MemoryRepository()
        self.client = ClientService(client_repository)

    def test_books(self):
        # print(self.book.repository.get_all_books())
        self.assertEqual(len(self.book.get_all_books()), 20)
        self.book.add_books(100, "The Night Circus", "Erin Morgenstern")
        self.assertEqual(len(self.book.get_all_books()), 21)

        object = Book(1, "The Martian", "Andy Weir")
        self.book.update(object)
        new_book = self.book.repository.find_by_id(1)
        self.assertEqual(new_book.title, "The Martian")
        self.assertEqual(new_book.author, "Andy Weir")
        find_title = self.book.find_title("The Marti")
        self.assertEqual(find_title[0].title, "The Martian")
        find_author = self.book.find_author("Andy We")
        self.assertEqual(find_author[0].author, "Andy Weir")

        self.book.remove_books(100)
        self.assertEqual(len(self.book.get_all_books()), 20)


    def test_clients(self):
        self.assertEqual(len(self.client.get_all_clients()), 20)
        self.client.add_clients(100, "Eduarda Ciobanu")
        self.assertEqual(len(self.client.get_all_clients()), 21)

        object = Client(1, "Alexia Bortos")
        self.client.update(object)
        client = self.client.repository.find_by_id(1)
        self.assertEqual(client.name, "Alexia Bortos")
        find_name = self.client.find_name("Alexia Bor")
        self.assertEqual(find_name[0].name, "Alexia Bortos")

        self.client.remove_clients(100)
        self.assertEqual(len(self.client.get_all_clients()), 20)