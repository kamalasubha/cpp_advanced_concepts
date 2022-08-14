// c++20_1
// PS C:\Users\KAMALASUBHA\OneDrive\Documents\C++ advanced concepts\c++20_2> g++ -std=c++2a .\c++20_1.cpp -o a.exe
#include <iostream>
#include <vector>

template <typename T>
void compare(T a, T b) {
    auto z = a <=> b;
    if (z == 0) {
        std::cout << "a == b" << std::endl;
    } else if (z < 0) {
        std::cout << "a < b" << std::endl;
    } else {
        std::cout << "a > b" << std::endl;
    }
}

int main() {
    std::string x1 = "MCW TEAM";
    std::string y1 = "MCW";
    compare(x1, y1);
    std::vector<int> x2{1, 2, 3};
    std::vector<int> y2{1, 2, 3};
    compare(x2, y2);
    return 0;
}