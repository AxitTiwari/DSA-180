// etna time kyu le raha hai bro 😐

#include <iostream>

class Student {
    public:
        std::string name;
        int age;
        double gpa;

    Student(std::string name, int age, double gpa) {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }
};

class Human {
    public:
        std::string name;
        int age;

    Human(std::string x, int y) {
        name = x;
        age = y;
    }
};

int main() {

    // constructor = special method that is called when an object is instantiated
    //               used to initialize objects

    Student student1("Amar", 25, 3.9);

    std::cout << student1.name << "\n";
    std::cout << student1.age << "\n";
    std::cout << student1.gpa << "\n";

    return 0;
}