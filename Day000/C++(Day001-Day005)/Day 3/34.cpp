#include <iostream>
// * to be continued....  -> ok aa gaya

struct student {
    std::string name;
    double gpa;
    bool enrolled;
};

int main() {

    // struct

    student s1;
    s1.name = "Axit";
    s1.gpa = 4.8;
    s1.enrolled = true;

    std::cout << s1.name << " " << s1.gpa << " " << s1.enrolled << std::endl;

    student s2 = {"Sahil", 5, true};
    std::cout << s2.name << " " << s2.gpa << " " << s2.enrolled << std::endl;

    return 0;
}