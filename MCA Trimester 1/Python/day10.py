#python encapsulation 

class Student:
    def __init__(self, name, age):
        self.__name = name
        self.__age = age

    def display(self):
        print(self.__name)
        print(self.__age)
        
    def setAge(self, age):
        self.__age = age
        
s1=Student("Anjaney Putra", 21)
s1.display()

