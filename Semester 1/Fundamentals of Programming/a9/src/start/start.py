import configparser

from src.repository.BinaryRepository import BinaryBookRepository, BinaryClientRepository, BinaryRentalRepository
from src.repository.TextFileRepository import TextBookRepository, TextRentalRepository, TextClientRepository
from src.repository.MemoryRepository import MemoryRepository
from src.services import undo_redo_service
from src.services.book_services import BookService
from src.services.client_services import ClientService
from src.services.rental_services import RentalService
from src.services.undo_redo_service import UndoService
from src.ui.ui import UI


configuration = configparser.RawConfigParser()
configuration.read('settings.properties')
repository_configuration = configuration.get('Repositories', 'repository')
if repository_configuration == "memory":
    book_repository = MemoryRepository()
    client_repository = MemoryRepository()
    rental_repository = MemoryRepository()

elif repository_configuration == "text_files":
    book_repository = TextBookRepository(configuration.get('Repositories', 'books'))
    client_repository = TextClientRepository(configuration.get('Repositories', 'clients'))
    rental_repository = TextRentalRepository(configuration.get('Repositories', 'rentals'))

elif repository_configuration == "binary_files":
    book_repository = BinaryBookRepository(configuration.get('Repositories', 'books'))
    client_repository = BinaryClientRepository(configuration.get('Repositories', 'clients'))
    rental_repository = BinaryRentalRepository(configuration.get('Repositories', 'rentals'))


undo_service = UndoService()

# book_service = BookService(book_repository)
# client_service = ClientService(client_repository)
# rental_service = RentalService(book_service.repository, client_service.repository, book_repository, client_repository, rental_repository)
rental_service = RentalService(book_repository, client_repository, rental_repository)
book_service = BookService(book_repository, rental_service, undo_service)
client_service = ClientService(client_repository, rental_service, undo_service)
ui = UI(book_service, client_service, rental_service, undo_service)
ui.program_start()