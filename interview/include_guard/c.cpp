#include <iostream>

int main() {
    extern int f();
    extern int g();

    std::cout << f() + g() << std::endl;
    return 0;
}
