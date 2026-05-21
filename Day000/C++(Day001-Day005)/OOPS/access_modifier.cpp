#include <iostream>

class Teacher {
    private:
        double salaray;

    public:
        std::string name;
        std::string department;
        int age;
    
        void changeDeptartment(std::string newDepartment) {
            department = newDepartment;
        }

        double getSalary() {
            return salaray;
        }

        void setSalary(double s) {
            salaray = s;
        }
};

int main() {

    Teacher t1;
    t1.name = "Moon";
    t1.department = "lust";
    t1.age = 15;
    // t1.salary = 50000;

    std::cout << t1.getSalary() << std::endl;
    t1.setSalary(50000);
    std::cout << t1.getSalary() << std::endl;

    std::cout << t1.name << std::endl;
    std::cout << t1.department << std::endl;
    std::cout <<t1.age << std::endl;

    return 0;
}