#include <iostream>
using namespace std;

// ---------- Abstract Class ----------
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;

    // Virtual destructor (good practice)
    virtual ~Shape() {}
};

// ---------- Derived Class ----------
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

// ---------- Derived Class ----------
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
};

// ---------- Main Function ----------
int main() {

    // Base class pointer (abstraction)
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw();   // Calls Circle's draw()
    shape2->draw();   // Calls Rectangle's draw()

    delete shape1;
    delete shape2;

    return 0;
}
