from src.domain.student import Student
from src.repository.MemoryRepository import MemoryRepository

class TextFileRepository(MemoryRepository):
    def __init__(self, file_name="students.txt"): #default value
        self._file_name = file_name
        super(TextFileRepository, self).__init__(False)
        self._load_file()

    def _load_file(self):
        lines = []

        try:
            input_stream = open(self._file_name, "rt")
            lines = input_stream.readlines()  # each students HAS TO BE on its own line
            input_stream.close()
        except IOError:
            pass

        for line in lines:
            current_line = line.split(",")
            new_student = Student(int(current_line[0].strip()), current_line[1].strip(), int(current_line[2].strip())) #for white spaces
            super().add_student(new_student)

    def _save_file(self):
        output_stream = open(self._file_name, "wt")
        for student in self.get_all_students():
            student_string = str(student.get_id()) + "," + student.get_name() + "," + str(student.get_group()) + "\n"
            output_stream.write(student_string)
        output_stream.close()

    def erase_data(self):
        super().erase_data()
        open(self._file_name, "w").close()

    def add_students(self, new_student: Student):
        super().add_student(new_student)
        self._save_file()

    def filter_students(self, group):
        super().filter_students(group)
        self._save_file()

    def undo_last_operation(self):
        super().undo_last_operation()
        self._save_file()