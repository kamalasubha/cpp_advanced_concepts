#include <iostream>
#include <memory>
#include <utility>

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

// Pass to a function
void passIn(std::shared_ptr<person> p) {
    std::cout << "Inside passIn" << std::endl;
    p->printName();
    std::cout << "P count:"  << p.use_count() << std::endl;
}

// Return unique pointer as a function return value
std::shared_ptr<person> passOut() {
    std::cout << "Inside passOut" << std::endl;
    auto cand = std::make_shared<person>("Mike");
    return cand;
}

int main()
{
    std::shared_ptr<person> cand_1(new person{"Tom"});
    std::cout << "Candidate 1 Use count = " << cand_1.use_count() << std::endl;
    std::shared_ptr<person> cand_2;
    cand_1.reset(new person("John"));
    std::cout << "Candidate 1 Use count = " << cand_1.use_count() << std::endl;
    cand_2 = std::make_shared<person>("Jane");
    std::cout << "Candidate 2 Use count = " << cand_2.use_count() << std::endl;

    std::cout << "Candidate1 name = " << cand_1->name << '\n';
    std::cout << "Candidate2 name = " << cand_2.get()->name << '\n';

    std::swap(cand_1, cand_2);
 
    std::cout << "Candidate1 name = " << cand_1->name << '\n';
    std::cout << "Candidate2 name = " << cand_2.get()->name << '\n';
    std::shared_ptr<person> cand_3 = std::move(cand_1);
    auto cand_4 = cand_3;
    cand_3->printName();
    std::cout << "Candidate 3 Use count = " << cand_3.use_count() << std::endl;

    if (cand_1) {
        cand_1->printName();
    } else {
        std::cout << "cand_1 is null" << std::endl;
    }
    cand_3->printName();

    passIn(cand_3);
    std::cout << "Candidate 3 Use count = " << cand_3.use_count() << std::endl;

    cand_3 = passOut();
    cand_3->printName();
    std::cout << "Candidate 3 Use count = " << cand_3.use_count() << std::endl;

    cand_4->printName();
    std::cout << "Candidate 4 Use count = " << cand_4.use_count() << std::endl;
    
}