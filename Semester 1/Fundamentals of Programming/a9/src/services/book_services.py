from src.domain import book
from src.domain.book import Book, import_books

from src.repository.MemoryRepository import MemoryRepository, RepositoryError
from src.services.undo_redo_service import Command, Operation, CascadedOperation


class BookService():
    def __init__(self, repository, rental_service, undo_redo_service):
        self.repository = repository  #merge si metoda de la a7?
        self.rental_service = rental_service
        self.undo_redo_service = undo_redo_service
        self.generate_books()

    def generate_books(self):
        if self.get_all_books() == []:
            books = import_books()
            for book in books:
                self.repository.add(book)

    def add_books(self, book_id, title, author):
        book = Book(book_id, title, author)
        self.repository.add(book)

        undo = Command(self.repository.remove, book.id)
        redo = Command(self.repository.add, book)
        operation = Operation(undo, redo)
        self.undo_redo_service.register(operation)

    def remove_books(self, book_id):
        book = self.repository.remove(book_id)

        # Register book for undo/redo
        undo = Command(self.repository.add, book)
        redo = Command(self.repository.remove, book_id)
        operations = Operation(undo, redo)
        self.undo_redo_service.register(operations)

        # Remove the book's rentals from repo
        # rentals = self.rental_service.filter_rentals(None, book_id)
        # for rental in rentals:
        #     self.rental_service.delete_rental(rental.id)
        #
        # # Register rentals for undo/redo
        # for rental in rentals:
        #     redo = Command(self.rental_service.delete_rental, rental.id)
        #     undo = Command(self.rental_service.rent_book, rental)
        #     operations.append(Operation(undo, redo))
        #
        # self.undo_redo_service.register(CascadedOperation(*operations))

    def get_all_books(self):
        return self.repository.get_all_objects()

    def search_id(self, id):
        return self.repository.find_by_id(id)

    def find_title(self, book_title):
        books_with_given_title = []
        for book in self.repository.object_list:
            if book.title.lower() == book_title.lower() or book_title.lower() in book.title.lower():
                books_with_given_title.append(book)
        if len(books_with_given_title) == 0:
            raise RepositoryError("Not found.")
        return books_with_given_title

    def find_author(self, book_author):
        books_with_given_author = []
        for book in self.repository.object_list:
            if book.author.lower() == book_author.lower() or book_author.lower() in book.author.lower():
                books_with_given_author.append(book)
        if len(books_with_given_author) == 0:
            raise RepositoryError("Not found.")
        return books_with_given_author

    def update(self, book):
        # return self.repository.update(book)

        previous_book = self.repository.update(book)

        # Register the book for undo/redo
        undo = Command(self.repository.update, previous_book)
        redo = Command(self.repository.update, book)
        operations = Operation(undo, redo)
        self.undo_redo_service.register(operations)

        # # Remove the previous book's rentals from repo
        # rentals = self.rental_service.filter_rentals(None, previous_book.id)
        # for rental in rentals:
        #     self.rental_service.delete_rental(rental.id)
        #
        # # Register rentals for undo/redo
        # for rental in rentals:
        #     redo = Command(self.rental_service.delete_rental, rental.id)
        #     undo = Command(self.rental_service.rent_book, rental.book_id, rental.client_id)
        #     operations.append(Operation(undo, redo))
        #
        # self.undo_redo_service.register(CascadedOperation(*operations))



    # def search_title(self, title):
    #     return self.repository.find_title(title)


    # def search_author(self, author):
    #     return self.repository.find_author(author)