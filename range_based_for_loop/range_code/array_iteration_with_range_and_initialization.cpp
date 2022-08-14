#include <iostream>

int main() { 
    for (int x1[] = {1, 2, 3}; int c : x1) {
        std::cout << c << std::endl;
    }
    //std::cout << x1[0] << std::endl;
    return 0;
}