#include <iostream>

class Stove {
    private:
        int temperature = 0;
    
    public:
        Stove(int temp) {
            setTemperature(temp);
        }

        int getTemperature() {
            return temperature;
        }

        void setTemperature(int temp) {
            if (temp < 0) {
                temperature = 0;
            }
            else if (temp > 10) {
                temperature = 10;
            }
            else {
                temperature = temp;
            }
        }
};

int main() {

    // getters and setters = special methods used to access private attributes
    Stove stove1(11);

    // stove1.setTemperature(-2);

    std::cout << stove1.getTemperature() << std::endl;

    return 0;
}