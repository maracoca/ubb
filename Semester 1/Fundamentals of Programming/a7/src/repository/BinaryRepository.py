import pickle

from src.domain.student import Student
from src.repository.MemoryRepository import MemoryRepository


class BinaryFileRepository(MemoryRepository):
    def __init__(self, file_name="students.bin"):
        self._file_name = file_name
        super(BinaryFileRepository, self).__init__(False)
        self._load_file()


    def _load_file(self):
        try:
            input_stream = open(self._file_name, 'rb')
            object = pickle.load(input_stream)
        except EOFError:
            return
        for new_student in object:
            super().add_student(new_student)
        input_stream.close()

    def _save_file(self):
        output_stream = open(self._file_name, "wb")
        pickle.dump(self.get_all_students(), output_stream)
        output_stream.close()

    def erase_data(self):
        super().erase_data()
        open(self._file_name, "w").close()

    def add_student(self, new_student: Student):
        super().add_student(new_student)
        self._save_file()

    def filter_students(self, group: int):
        super().filter_students(group)
        self._save_file()

    def undo_last_operation(self):
        super().undo_last_operation()
        self._save_file()
