// C++ program to demonstrate shared_ptr
#include <iostream>
#include <memory>

class A {
public:
	void show()
	{
		std::cout << "A::show()" << std::endl;
	}
};

int main()
{
    A *a = new A();
	std::shared_ptr<A> p1(a);

	std::cout << p1.get() << std::endl;
	p1->show();
	std::shared_ptr<A> p2(p1);
	p2->show();

	std::cout << p1.get() << std::endl;
	std::cout << p2.get() << std::endl;

	std::cout << p1.use_count() << std::endl;
	std::cout << p2.use_count() << std::endl;

	p1.reset();

	std::cout << p1.get() << std::endl;
	std::cout << p2.use_count() << std::endl;
	std::cout << p2.get() << std::endl;

    p1->show();
    p2->show();

    return 0;
}
