
from unittest import TestCase

from src.domain.student import Student
from src.services.StudentService import StudentService

class TestStudent(TestCase):
    def test_student_id(self):
        student = Student("12", "Mara", "912")
        self.assertEqual(student.get_id(), "12")

    def test_student_name(self):
        student = Student("12", "Mara", "912")
        self.assertEqual(student.get_name(), "Mara")

    def test_student_group(self):
        student = Student("12", "Mara", "912")
        self.assertEqual(student.get_group(), "912")

# class TestMemory(TestCase):
#     def setUp(self):
#         self.instruction = StudentService()
#
#     def test_add_memory_repository(self):
#         first_element = 0
#         self.assertEqual(len(self.instruction.repository._students_storage), 0)
#         self.instruction.add_student(1, 'Mara', 90)
#         self.assertEqual(len(self.instruction.repository._students_storage), 1)
#         number = self.instruction.repository._students_storage[first_element]
#         student = Student(1, 'Mara', 90)
#         self.assertEqual(student.get_id(), 1)
#         self.assertEqual(student.get_name(), 'Mara')
#         self.assertEqual(student.get_group(), 90)
#         try:
#             self.instruction.add_student("word1", "word2", "word3")
#         except ValueError as ve:
#             self.assertEqual(len(self.instruction.repository._students_storage), 1)
#
#
# if __name__ == "__main__":
#     unittest.main()