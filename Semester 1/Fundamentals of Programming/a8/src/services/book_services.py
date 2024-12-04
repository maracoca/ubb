from src.domain.book import Book, import_books
from src.repository.memory_repository import MemoryRepository, RepositoryError
from src.repository.memory_repository import MemoryRepository


class BookService():
    def __init__(self, repository):
        self.repository = repository
        self.generate_books()

    def generate_books(self):
        books = import_books()
        for book in books:
            self.repository.add(book)

    def add_books(self, book_id, title, author):
        book = Book(book_id, title, author)
        self.repository.add(book)

    def remove_books(self, book_id):
        self.repository.remove(book_id)

    # def list_books(self):
    #     self.repository.list_objects()

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
        return self.repository.update(book)
