#include <iostream>

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
	SmartPtr<int> ptr(new int());
	*ptr = 20;
	std::cout << *ptr;
	return 0;
}
