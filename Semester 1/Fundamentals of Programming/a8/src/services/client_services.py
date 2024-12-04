from src.domain.client import Client, import_clients
from src.repository.memory_repository import MemoryRepository, RepositoryError


class ClientService():
    def __init__(self, repository):
        self.repository = repository
        self.generate_client()

    def generate_client(self):
        clients = import_clients()
        for client in clients:
            self.repository.add(client)

    def add_clients(self, client_id, name):
        client = Client(client_id, name)
        self.repository.add(client)

    def remove_clients(self, client_id):
        self.repository.remove(client_id)

    # def list_clients(self):
    #     self.repository.list_objects()

    def get_all_clients(self):
        return self.repository.get_all_objects()

    def find_name(self, client_name):
        clients_with_given_name = []
        for client in self.repository.get_all_objects():
            if client.name.lower() == client_name.lower() or client_name.lower() in client.name.lower():
                clients_with_given_name.append(client)
        if len(clients_with_given_name) == 0:
            raise RepositoryError("Not found.")
        return clients_with_given_name

    def update(self, client):
        return self.repository.update(client)