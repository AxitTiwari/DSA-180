#include <iostream>

class Human {
    public:
        std::string name;
        std::string occupation;
        int age;

        void eat() {
            std::cout << "This person is eating\n";
        }
        void drink() {
            std::cout << "this person is drinking\n";
        }
        void sleep() {
            std::cout << "this person is sleeping\n";
        }

};

int main() {

    // object = A collection of attributes and methods

    Human human1;
    Human human2;

    human1.name = "Rick";
    human1.occupation = "Developer";
    human1.age = 35;

    human2.name = "Samir";
    human2.occupation = "student";
    human2.age = 19;

    std::cout << human1.name << "\n";
    std::cout << human1.occupation << "\n";
    std::cout << human1.age << "\n";

    human1.eat();
    human1.drink();
    human1.sleep();

    human2.eat();
    human2.drink();
    human2.sleep();

    return 0;
}