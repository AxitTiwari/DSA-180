#include <iostream>

using std::cout;
using std::endl;

// wrapping up data members and functions into a single unit -> class
class Troop {
private:
    int hp;
    int dps;
    int level;

public:
    Troop(int h, int d, int l) : hp(h), dps(d), level(l) {}
};

int main() {

    Troop pekka(8000, 10000, 10);

    Troop valkyrie(4000, 500, 8);

    return 0;
}