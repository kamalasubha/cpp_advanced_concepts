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


// A generic smart pointer class
template <class T>
class SmartPtr {
	T* ptr; // Actual pointer
public:
	// Constructor
	explicit SmartPtr(T* p = NULL) { ptr = p; }

	// Destructor
	~SmartPtr() { delete (ptr); }

	// Overloading dereferencing operator
	T& operator*() {
        return *ptr; 
    }

	// Overloading arrow operator
	T* operator->() { return ptr; }
};

int main()
{
	SmartPtr<int> ptr1(new int());
	*ptr1 = 20;
	std::cout << *ptr1 << std::endl;
	SmartPtr<person> ptr2(new person("John"));
	ptr2->printName();
	return 0;
}
