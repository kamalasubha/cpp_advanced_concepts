#include <numeric>
#include <vector>
#include <iostream>
#include <concepts>

template <typename T> 
requires std::integral<T> || std::floating_point<T>
constexpr double Average(std::vector<T> const &vec) {
    const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);        
    return sum / vec.size();
}

int main() {
    std::vector<int> int_arr = {1, 2, 3, 4, 5};
    std::cout << Average(int_arr) << '\n';     
    std::vector<std::string> str_arr = {"MCW", "ML", "COE"};
    std::cout << Average(str_arr) << '\n';                   
}