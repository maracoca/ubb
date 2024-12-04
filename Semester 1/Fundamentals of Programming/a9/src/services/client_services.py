from src.domain.client import Client, import_clients

from src.repository.MemoryRepository import MemoryRepository, RepositoryError
from src.services.undo_redo_service import Command, Operation, CascadedOperation


class ClientService():
    def __init__(self, repository, rental_service, undo_redo_service):
        # self.repository = MemoryRepository()
        self.repository = repository
        self.undo_redo_service = undo_redo_service
        self.rental_service = rental_service
        self.generate_client()

    def generate_client(self):
        if self.get_all_clients() == []:
            clients = import_clients()
            for client in clients:
                self.repository.add(client)

    def add_clients(self, client_id, name):
        client = Client(client_id, name)
        self.repository.add(client)

        undo = Command(self.repository.remove, client.id)
        redo = Command(self.repository.add, client)
        operation = Operation(undo, redo)
        self.undo_redo_service.register(operation)

    def remove_clients(self, client_id):
        client = self.repository.remove(client_id)

        undo = Command(self.repository.add, client)
        redo = Command(self.repository.remove, client_id)
        operations = Operation(undo, redo)
        self.undo_redo_service.register(operations)

        # rentals = self.rental_service.filter_rentals(client_id, None)
        # for rental in rentals:
        #     self.rental_service.delete_rental(rental.id)
        #
        # for rental in rentals:
        #     redo = Command(self.rental_service.delete_rental, rental.id)
        #     undo = Command(self.rental_service.rent_book, rental)
        #     operations.append(Operation(undo, redo))
        #
        # self.undo_redo_service.register(CascadedOperation(*operations))


    def get_all_clients(self):
        return self.repository.get_all_objects()

    # def search_name(self, name):
    #     return self.repository.find_name(name)

    def find_name(self, client_name):
        clients_with_given_name = []
        for client in self.repository.object_list:
            if client.name.lower() == client_name.lower() or client_name.lower() in client.name.lower():
                clients_with_given_name.append(client)
        if len(clients_with_given_name) == 0:
            raise RepositoryError("Not found.")
        return clients_with_given_name

    def update(self, client):
        # return self.repository.update(client)

        previous_client = self.repository.update(client)

        undo = Command(self.repository.update, previous_client)
        redo = Command(self.repository.update, client)
        operations = Operation(undo, redo)
        self.undo_redo_service.register(operations)

        # rentals = self.rental_service.filter_rentals(None, previous_client.id)
        # for rental in rentals:
        #     self.rental_service.delete_rental(rental.id)
        #
        # for rental in rentals:
        #     redo = Command(self.rental_service.delete_rental, rental.id)
        #     undo = Command(self.rental_service.rent_book, rental.book_id, rental.client_id)
        #     operations.append(Operation(undo, redo))
        #
        # self.undo_redo_service.register(CascadedOperation(*operations))