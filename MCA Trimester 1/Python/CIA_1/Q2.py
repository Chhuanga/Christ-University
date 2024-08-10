# Q2 Library Management

class LibraryItem:
    def __init__(self, library_name, location):
        self.library_name = library_name
        self.location = location
        self.availability = True

    def checkout(self):
        self.availability = False
        print("Book checked out")

    def return_book(self):
        self.availability = True
        print("Book returned")

    def update_availability(self, new_status):
        self.availability = new_status

1
class Book(LibraryItem):
    def __init__(self, library_name, location, book_name, author, genre, isbn):
        super().__init__(library_name, location)
        self.book_name = book_name
        self.author = author
        self.genre = genre
        self.isbn = isbn

    def checkout(self):
        self.availability = False
        print("Book checked out")

    def return_book(self):
        self.availability = True
        print("Book returned")

    def get_details(self):
        print(f"Title: {self.book_name}")
        print(f"Author: {self.author}")
        print(f"Genre: {self.genre}")
        print(f"ISBN: {self.isbn}")

    def add_to_library(self):
        print("Book added to library")


def display_menu():
    print("\nLibrary Menu:")
    print("1. Add Book")
    print("2. Checkout Book")
    print("3. Return Book")
    print("4. View Book Details")
    print("5. Exit")


def add_book(library):
    library_name = input("Enter library name: ")
    location = input("Enter location: ")
    book_name = input("Enter book name: ")
    author = input("Enter author: ")
    genre = input("Enter genre: ")
    isbn = input("Enter ISBN: ")
    book = Book(library_name, location, book_name, author, genre, isbn)
    library.append(book)
    book.add_to_library()


def checkout_book(library):
    book_name = input("Enter the name of the book to checkout: ")
    for book in library:
        if book.book_name == book_name:
            if book.availability:
                book.checkout()
            else:
                print("Book is already checked out")
            return
    print("Book not found")


def return_book(library):
    book_name = input("Enter the name of the book to return: ")
    for book in library:
        if book.book_name == book_name:
            if not book.availability:
                book.return_book()
            else:
                print("Book is already available")
            return
    print("Book not found")


def view_book_details(library):
    book_name = input("Enter the name of the book to view details: ")
    for book in library:
        if book.book_name == book_name:
            book.get_details()
            return
    print("Book not found")


def main():
    library = []
    while True:
        display_menu()
        choice = input("Enter your choice: ")
        if choice == '1':
            add_book(library)
        elif choice == '2':
            checkout_book(library)
        elif choice == '3':
            return_book(library)
        elif choice == '4':
            view_book_details(library)
        elif choice == '5':
            print("Exiting the library system.")
            break
        else:
            print("Invalid choice. Please try again.")


1
main()