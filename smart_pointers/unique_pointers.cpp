#include <iostream>
#include <memory>
#include <utility>

// Class person with Name param
class person {
public:
    std::string name;
    person(std::string name) : name(name) {}
    ~person() {
        std::cout << "Person destructed :" << name << std::endl;
    }
    void printHello() {
        std::cout << "Hello World " << std::endl;
    }
    void printName() {
        std::cout << "Name: " << name << std::endl;
    }
};

// Pass to a function
void passIn(std::unique_ptr<person> p) {
    std::cout << "Inside passIn" << std::endl;
    p->printName();
}

// Return unique pointer as a function return value
std::unique_ptr<person> passOut() {
    std::cout << "Inside passOut" << std::endl;
    auto cand = std::make_unique<person>("Mike");
    return cand;
}

// Oberver function
void printName_pointer(person *p) {
    p->printName();
}

// Oberver function
void printName_reference(person &p) {
    p.printName();
}

int main()
{
    std::unique_ptr<person> cand_1(new person{"Tom"});
    std::unique_ptr<person> cand_2;
    cand_1.reset(new person("John"));
    cand_2 = std::make_unique<person>("Jane");

    std::cout << "Candidate1 name = " << cand_1->name << '\n';
    std::cout << "Candidate2 name = " << cand_2.get()->name << '\n';

    std::swap(cand_1, cand_2);
 
    std::cout << "Candidate1 name = " << cand_1->name << '\n';
    std::cout << "Candidate2 name = " << cand_2.get()->name << '\n';

    std::unique_ptr<person> cand_3 = std::move(cand_1);

    cand_1->printHello();
    cand_3->printHello();

    if (cand_1) {
        cand_1->printName();
    }
    else {
        std::cout << "cand_1 is null" << std::endl;
    }
    cand_3->printName();

    passIn(std::move(cand_3));

    if (cand_3) {
        cand_3->printName();
    }
    else {
        std::cout << "cand_3 is null" << std::endl;
    }

    cand_3 = passOut();
    if (cand_3) {
        cand_3->printName();
    }
    else {
        std::cout << "cand_3 is null" << std::endl;
    }

    printName_pointer(cand_3.get());
    printName_reference(*cand_3);

    
}