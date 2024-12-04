import pickle

from src.repository.MemoryRepository import MemoryRepository


class BinaryBookRepository(MemoryRepository):
    def __init__(self, file_name="Books.bin"):
        self._file_name = file_name
        super().__init__()
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

    def _load(self):
        object = []
        try:
            input_stream = open(self._file_name, 'rb')
            object = pickle.load(input_stream)
            input_stream.close()
        except IOError:
            pass
        for new_book in object:
            super().add(new_book)

    def _save(self):
        output_stream = open(self._file_name, "wb")
        pickle.dump(self.get_all_objects(), output_stream)
        output_stream.close()

class BinaryClientRepository(MemoryRepository):
    def __init__(self, file_name="Clients.bin"):
        self._file_name = file_name
        super().__init__()
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

    def _load(self):
        object = []
        try:
            input_stream = open(self._file_name, 'rb')
            object = pickle.load(input_stream)
            input_stream.close()
        except IOError:
            pass
        for new_client in object:
            super().add(new_client)

    def _save(self):
        output_stream = open(self._file_name, "wb")
        pickle.dump(self.get_all_objects(), output_stream)
        output_stream.close()

class BinaryRentalRepository(MemoryRepository):
    def __init__(self, file_name="Rentals.bin"):
        self._file_name = file_name
        super().__init__()
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

    def _load(self):
        object = []
        try:
            input_stream = open(self._file_name, 'rb')
            object = pickle.load(input_stream)
            input_stream.close()
        except IOError:
            pass
        for new_rental in object:
            super().add(new_rental)

    def _save(self):
        output_stream = open(self._file_name, "wb")
        pickle.dump(self.get_all_objects(), output_stream)
        output_stream.close()

