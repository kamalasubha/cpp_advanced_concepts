#include <iostream>

template <class T>
constexpr T pi = T(3.1415926535897932385L); // variable template

int main() {
    std::cout << pi<float> << std::endl; // 3.14159
    std::cout << pi<int> << std::endl;   // 3
    return 0;
}