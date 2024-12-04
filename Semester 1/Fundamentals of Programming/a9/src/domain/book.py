class Book():
    def __init__(self, id, title, author):
        self._id = id
        self._title = title
        self._author = author
        self.is_available = True

    @property
    def id(self):
        return self._id

    @id.setter
    def id(self, book_id):
        self._id = book_id

    @property
    def title(self):
        return self._title

    @title.setter
    def title(self, title):
        # if title not in ["a", "b", "c"]:
        #     raise ValueError("Incorrect title")
        self._title = title

    @property
    def author(self):
        return self._author

    @author.setter
    def author(self, author):
        self._author = author

    def __str__(self):
        return f"id: {self.id}, title: {self.title}, author: {self.author}"

def import_books():
    books = []
    book_id = 1
    title = ["The Catcher in the Rye", "1984", "Brave New World", "The Great Gatsby",
             "One Hundred Years of Solitude", "The Catcher in the Rye", "Moby-Dick", "The Odyssey",
             "The Lord of the Rings", "War and Peace", "Crime and Punishment", "The Brothers Karamazov",
             "The Shining", "The Hitchhiker's Guide to the Galaxy", "The Martian", "Slaughterhouse-Five",
             "The Hunger Games", "Dune", "The Chronicles of Narnia", "The Color Purple"]
    author = ["J.D. Salinger", "George Orwell", "Aldous Huxley", "F. Scott Fitzgerald", "Gabriel Garcia Marquez",
              "J.D. Salinger", "Herman Melville", "Homer", "J.R.R. Tolkien", "Leo Tolstoy", "Fyodor Dostoevsky",
              "Fyodor Dostoevsky", "Stephen King", "Douglas Adams", "Andy Weir", "Kurt Vonnegut", "Suzanne Collins",
              "Frank Herbert", "C.S. Lewis", "Alice Walker"]
    for i in range(20):
        books.append(Book(book_id + i, title[i], author[i]))
    return books

# def get_book():
#     id = int(input("id "))
#     title = input("title ")
#     author = input("author ")
#     return Book(id, title, author)
#
# def main():
#     book = get_book()
#     #book.title = "l"
#     print(book)
#
# main()
