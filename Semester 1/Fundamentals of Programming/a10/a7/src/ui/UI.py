from src.repository.TextFileRepository import TextFileRepository
from src.services.StudentService import StudentService

class UI:
  def __init__(self):
    # repository = MemoryRepository()
    repository = TextFileRepository()
    # repository = BinaryFileRepository()
    self.__student_service = StudentService(repository)

  def print_ui(self):
    while True:
      print("1. Add a student")
      print("2. Disaply all students")
      print("3. Filter students by group")
      print("4. Undo the last operation")
      print("5. Exit the application")

      option = int(input("Choose your option: "))
      add = 1
      display = 2
      filter = 3
      undo = 4
      exit = 5

      if option == add:
        id = int(input("What is the ID of the student? "))
        name = input("What is the name of the student? ")
        group = int(input("In which group is the student? "))
        self.__student_service.add_student(id, name, group)
      elif option == display:
        students = self.__student_service.get_all_students()
        for stud in students:
          print(stud)
      elif option == filter:
        group = int(input("Which group would you like to remove? "))
        self.__student_service.filter_students(group)
      elif option == undo:
        self.__student_service.undo_last_operation()
      elif option == exit:
        return
