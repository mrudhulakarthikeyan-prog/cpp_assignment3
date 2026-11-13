#include <iostream>
class OrderDemo {
    int first;
    int second;
public:
    // Deliberately wrong initializer-list order for -Wreorder investigation.
    OrderDemo() : second(20), first(10) {}
    void show() const { std::cout << first << ' ' << second << '\n'; }
};
int main() { OrderDemo x; x.show(); }
