class Student:
    def __init__(self, id, name, group):
        # if not isinstance(id, int):
        #     raise ValueError("The id must be an integer! ")
        # if not isinstance(name, str):
        #     raise ValueError("The name must be an string! ")
        # if not isinstance(group, int):
        #     raise ValueError("The group must be an integer! ")
        # if isinstance(group, int) and group > 0:
        #     raise ValueError("The group must be a positive integer! ")

        self._id = id
        self._name = name
        self._group = group

    def get_id(self):
        return self._id

    def get_name(self):
        return self._name

    def get_group(self):
        return self._group

    def __str__(self):
        return f"id {self._id} name {self._name} group {self._group}"

    # @staticmethod
    # def generate_students():
    #     return [Student(1, "Eduarda", 912),
    #             Student(2, "Alexia", 912),
    #             Student(3, "Alex", 911),
    #             Student(4, "Mihai", 913),
    #             Student(5, "Iulia", 911),
    #             Student(6, "Andrei", 914),
    #             Student(7, "Bogdan", 914),
    #             Student(8, "Miruna", 913),
    #             Student(9, "Tudor", 913),
    #             Student(10, "Mircea", 912)]
