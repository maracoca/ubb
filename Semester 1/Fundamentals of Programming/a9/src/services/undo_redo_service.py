class Command:
    def __init__(self, function_name, *function_parameters):
        self.__function_name = function_name
        self.__function_parameters = function_parameters

    def call(self):
        return self.__function_name(*self.__function_parameters)

    def __call__(self, *args, **kwargs):
        return self.call()


class Operation:
    def __init__(self, undo_command: Command, redo_command: Command):
        self.__undo = undo_command
        self.__redo = redo_command

    def undo(self):
        return self.__undo()

    def redo(self):
        return self.__redo()


class CascadedOperation:
    def __init__(self, *operations):
        self.__operations = operations

    def undo(self):
        for operation in self.__operations:
            operation.undo()

    def redo(self):
        for operation in self.__operations:
            operation.redo()


class UndoRedoError(Exception):
    pass


class UndoService:
    def __init__(self):
        self.__undo = []
        self.__redo = []

    def register(self, operation):
        self.__undo.append(operation)

    def undo(self):
        if not self.__undo:
            raise UndoRedoError("No more undos!")

        last_operation = self.__undo.pop()
        self.__redo.append(last_operation)
        last_operation.undo()

    def redo(self):
        if not self.__redo:
            raise UndoRedoError("No more redos!")

        last_operation = self.__redo.pop()
        self.__undo.append(last_operation)
        last_operation.redo()

