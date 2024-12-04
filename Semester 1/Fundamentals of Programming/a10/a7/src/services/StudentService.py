from src.domain.student import Student
from src.repository.MemoryRepository import MemoryRepository

class StudentService:
  def __init__(self, repository):
    self.repository = repository

  def add_student(self, id, name, group):
    new_student = Student(id, name, group)
    self.repository.add_students(new_student)

  def filter_students(self, group):
    self.repository.filter_students(group)

  def get_all_students(self):
    return self.repository.get_all_students()

  def undo_last_operation(self):
    self.repository.undo_last_operation()

  def clear_students(self):
    self.repository.erase_data()
