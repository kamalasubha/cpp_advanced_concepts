#include <iostream>

// Class person with Name param
class person {
public:
    std::string name;
    person(std::string name) : name(name) {}
    ~person() {
        std::cout << "Person destructed : " << name << std::endl;
    }
    void printName() {
        std::cout << "Name: " << name << std::endl;
    }
};


int main()
{
	person* ptr = new person("John");
	std::cout << ptr->name << std::endl;
    delete ptr;
	return 0;
}
