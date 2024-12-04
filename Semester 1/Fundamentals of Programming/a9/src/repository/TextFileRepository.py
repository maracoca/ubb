from src.domain.book import Book
from src.domain.client import Client
from src.domain.rental import Rental
from src.repository.MemoryRepository import MemoryRepository


class TextBookRepository(MemoryRepository):

    def __init__(self, file_name = 'Books.txt'):
        super().__init__()
        self._file_name = file_name
        self._load()

    def find_by_id(self, id):
        return super().find_by_id(id)

    def add(self, book):
        super().add(book)
        self._save()

    def remove(self, book_id):
        super().remove(book_id)
        self._save()

    def update(self, book):
        super().update(book)
        self._save()

    def get_all_objects(self):
        return super().get_all_objects()

    # def delete_all_books(self):
    #     super().delete_all_books()
    #     self.__save()

    def _save(self):
        output_stream = open(self._file_name, 'wt')
        for book in self.get_all_objects():
            line = str(book.id) + ',' + book.title + ',' + book.author + "\n"
            output_stream.write(line)
        output_stream.close()

    def _load(self):
        lines = []
        try:
            input_stream = open(self._file_name, 'rt')
            lines = input_stream.readlines()
            input_stream.close()
        except IOError:
            pass

        for line in lines:
            # if line == '\n':
            #     break
            # line = line.replace('\n', '').split(';')
            current_line = line.split(",")
            super().add(Book(int(current_line[0].strip()), current_line[1].strip(), current_line[2].strip()))

class TextClientRepository(MemoryRepository):

    def __init__(self, file_name = 'Clients.txt'):
        super().__init__()
        self._file_name = file_name
        self._load()

    def find_by_id(self, id):
        return super().find_by_id(id)

    def add(self, client):
        super().add(client)
        self._save()

    def remove(self, client_id):
        super().remove(client_id)
        self._save()

    def update(self, client):
        super().update(client)
        self._save()

    def get_all_objects(self):
        return super().get_all_objects()


    def _save(self):
        output_stream = open(self._file_name, 'wt')
        for client in self.get_all_objects():
            line = str(client.id) + ',' + client.name + "\n"
            output_stream.write(line)
        output_stream.close()

    def _load(self):
        lines = []
        try:
            input_stream = open(self._file_name, 'rt')
            lines = input_stream.readlines()
            input_stream.close()
        except IOError:
            pass

        for line in lines:
            # if line == '\n':
            #     break
            # line = line.replace('\n', '').split(';')
            current_line = line.split(",")
            super().add(Client(int(current_line[0].strip()), current_line[1].strip()))

class TextRentalRepository(MemoryRepository):

    def __init__(self, file_name = 'Rentals.txt'):
        super().__init__()
        self._file_name = file_name
        self._load()

    def find_by_id(self, id):
        return super().find_by_id(id)

    def add(self, rental):
        super().add(rental)
        self._save()

    def remove(self, rental_id):
        super().remove(rental_id)
        self._save()

    def update(self, rental):
        super().update(rental)
        self._save()

    def get_all_objects(self):
        return super().get_all_objects()


    def _save(self):
        output_stream = open(self._file_name, 'wt')
        for rental in self.get_all_objects():
            line = str(rental.id) + ',' + str(rental.book_id) + ',' + str(rental.client_id) + ',' + str(rental.rented_day) + ',' + str(rental.returned_day) + "\n"
            output_stream.write(line)
        output_stream.close()

    def _load(self):
        lines = []
        try:
            input_stream = open(self._file_name, 'rt')
            lines = input_stream.readlines()
            input_stream.close()
        except IOError:
            pass

        for line in lines:
            # if line == '\n':
            #     break
            # line = line.replace('\n', '').split(';')
            current_line = line.split(",")
            super().add(Rental(int(current_line[0].strip()), int(current_line[1].strip()), int(current_line[2].strip()), (current_line[3].strip()), (current_line[4].strip())))