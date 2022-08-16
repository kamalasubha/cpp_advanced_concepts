#include <iostream>
#include <memory>

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


int main(){

    // initial state
    std::shared_ptr<person> teacher = std::make_shared<person>("Jack");
    std::shared_ptr<person> coach = teacher;
    std::weak_ptr<person> wp = teacher;
    std::cout << "Teacher use count: " << teacher.use_count() << std::endl;
    std::cout << "Coach use count: " << coach.use_count() << std::endl;
    std::cout << "Weak pointer use count: " << wp.use_count() << std::endl;

    if (auto temp = wp.lock()) {
        temp->printName();
        std::cout << "Teacher use count: " << teacher.use_count() << std::endl;
        std::cout << "Coach use count: " << coach.use_count() << std::endl;
        std::cout << "Weak pointer use count: " << wp.use_count() << std::endl;
    } //  Jack
    
    // coach is reset
    coach.reset();

    std::cout << "Teacher use count: " << teacher.use_count() << std::endl;
    std::cout << "Coach use count: " << coach.use_count() << std::endl;
    std::cout << "Weak pointer use count: " << wp.use_count() << std::endl;


    // teacher is reset to Rose
    teacher.reset(new person("Rose"));

    std::cout << "Teacher use count: " << teacher.use_count() << std::endl;
    std::cout << "Coach use count: " << coach.use_count() << std::endl;
    std::cout << "Weak pointer use count: " << wp.use_count() << std::endl;

    
    if (wp.expired()) // true
        std::cout<< "The old teacher is gone" << std::endl; 
}