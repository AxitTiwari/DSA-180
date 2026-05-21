#include <iostream>

struct Car {
    std::string model;
    int year;
    std::string color;
};
void printCar(Car c);

int main() {

    Car car1;
    car1.model = "Toyota";
    car1.year = 2000;
    car1.color = "Green";

    Car car2;
    car2.model = "Toyota";
    car2.year = 2020;
    car2.color = "Blue";

    printCar(car1);
    printCar(car2);
    return 0;
}

void printCar(Car c) {
    std::cout << c.model << " " << c.year << " " << c.color << std::endl;
}