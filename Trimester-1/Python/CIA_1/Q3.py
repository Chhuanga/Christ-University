#Question No 3

class LibraryItem:
    def get_details(self):
        pass

class Magazine(LibraryItem):
    def __init__(self, title, issue_number):
        self.title = title
        self.issue_number = issue_number

    def get_details(self):
        return f"Magazine: {self.title}, Issue Number: {self.issue_number}"

class DVD(LibraryItem):
    def __init__(self, title, duration):
        self.title = title
        self.duration = duration

    def get_details(self):
        return f"DVD: {self.title}, Duration: {self.duration} minutes"

magazine = Magazine("National Geographic", 202)
dvd = DVD("Inception", 148)


print(magazine.get_details())
print(dvd.get_details())