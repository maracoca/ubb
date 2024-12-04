from src.domain.book import Book
from src.repository.memory_repository import MemoryRepository


class TextBookRepo(MemoryRepository):

    def __init__(self, file_name = '../Books.txt'):
        super().__init__()
        self._file_name = file_name
        self.__load()

    def find_by_id(self, id):
        return super().find_by_id(id)

    def add(self, book):
        super().add(book)
        self.__save()

    def remove(self, book_id):
        super().remove(book_id)
        self.__save()

    def update(self, book):
        super().update(book)
        self.__save()

    def get_all_objects(self):
        return super().get_all_objects()

    # def delete_all_books(self):
    #     super().delete_all_books()
    #     self.__save()

    def __save(self):
        output_stream = open(self._file_name, 'wt')
        for book in self.get_all_objects():
            line = str(book.id) + ',' + book.title + ',' + book.author + "\n"
            output_stream.write(line)
        output_stream.close()

    def __load(self):
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
                super().add(Book(int(current_line[0]), current_line[1], current_line[2]))