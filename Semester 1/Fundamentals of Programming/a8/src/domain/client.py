class Client():
    def __init__(self, id, name):
        self.id = id
        self._name = name

    @property
    def id(self):
        return self._id

    @id.setter
    def id(self, client_id):
        self._id = client_id

    @property
    def name(self):
        return self._name

    def __str__(self):
        return f"client id: {self.id}, name {self.name}"

def import_clients():
    clients = []
    client_id = 1
    name = ["Alexandra Popescu", "Andrei Ionescu", "Elena Dumitru", "Vlad Mihai", "Ioana Stanescu",
            "Radu Vasilescu", "Ana Dragomir", "Mihai Radulescu", "Maria Gheorghiu", "Cristian Tudor",
            "Alina Cojocaru", "Bogdan Neagu", "Larisa Dobre", "Florin Popa", "Elena Ionita", "Catalin Moldovan",
            "Raluca Dumitrescu", "Adrian Vasile", "Simona Marin", "Gabriel Pop"]
    for i in range(20):
        clients.append(Client(client_id + i, name[i]))
    return clients


# def get_client():
#     id = int(input("id "))
#     name = input("name ")
#     return Client(id, name)
#
# def main():
#     client = get_client()
#     #book.title = "l"
#     print(client)
#
# main()