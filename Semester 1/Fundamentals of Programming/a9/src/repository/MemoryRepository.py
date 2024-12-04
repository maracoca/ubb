class RepositoryError(Exception):
    def __init__(self, message_error="Repository Error!"):
        self.message = message_error

class MemoryRepository():
    def __init__(self):
        self.object_list = []

    def add(self, object):
        if self.find_by_id(object.id):
            raise RepositoryError("Object already exists!")
        self.object_list.append(object)

    def remove(self, id):
        object_to_delete = self.find_by_id(id)
        if self.find_by_id(id) is None:
            RepositoryError("You can't remove a book that does not exist!")
        for object in self.object_list:
            if object.id == id:
                self.object_list.remove(object)
        return object_to_delete

    # def list_objects(self):
    #     for object in self.object_list:
    #         print(object)

    def get_all_objects(self):
        return self.object_list

    def find_by_id(self, id):
        for object in self.object_list:
            if object.id == id:
                return object

    def update(self, object_to_be_updated):
        if self.find_by_id(object_to_be_updated.id) is None:
            raise RepositoryError("Object doesn't exist.")
        for i, object in enumerate(self.object_list):
            if object.id == object_to_be_updated.id:
                self.object_list[i] = object_to_be_updated
        return self.find_by_id(object_to_be_updated.id)
