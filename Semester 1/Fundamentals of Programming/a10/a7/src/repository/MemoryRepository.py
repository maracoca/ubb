from src.domain.student import Student
import random


class MemoryRepository:
  def __init__(self, generate_random=True):
    self._students_storage = []
    self._stack = []
    if generate_random:
      self.generate_random_students()

  def generate_random_students(self):
    list_of_names = ["Ana", "Bogdan", "Mihai", "Vlad", "Maria", "Antonia", "Irina", "Daria", "Ionut", "Tudor"]
    for i in range(10):
      id = random.randint(1,1000)
      name = random.choice(list_of_names)
      group = random.randint(911, 917)
      student = Student(id, name, group)
      self.add_student(student)

  def erase_data(self):
    self._students_storage.clear()

  def add_student(self, student):
    self._students_storage.append(student)
    self._stack.append(list(self._students_storage))

  def get_all_students(self):
    #for student in self._students_storage:
      #print(student)
    copy_of_students_storage = self._students_storage.copy()
    return copy_of_students_storage

  def filter_students(self, group):
    filtered_list_of_students = []
    for student in self._students_storage:
      if student.get_group() != group:
        filtered_list_of_students.append(student)
    self._students_storage = list(filtered_list_of_students)
    self._stack.append(list(self._students_storage))

  def undo_last_operation(self):
    length_original_stack = 1
    if len(self._stack) != length_original_stack:
      self._stack.pop()
      self._students_storage = list(self._stack[-1])
    else:
      raise ValueError("Your list is at the initial state")


