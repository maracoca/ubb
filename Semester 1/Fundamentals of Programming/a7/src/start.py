from src.domain.student import Student
from src.repository.MemoryRepository import MemoryRepository
from src.repository.TextFileRepository import TextFileRepository
from src.repository.BinaryRepository import BinaryFileRepository
from src.services.StudentService import StudentService
from src.ui.UI import UI

#repository = MemoryRepository()
repository = TextFileRepository()
#repository = BinaryFileRepository()

student_service = StudentService(repository)

ui = UI()
ui.print_ui()
