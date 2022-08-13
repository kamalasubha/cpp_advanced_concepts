#include <iostream>

struct Person{
    std::string Name;
    Person(std::string n):Name(n){}
};

int main(){

    // initial state
    auto teacher = std::make_shared<Person>("Jack");
    auto coach = teacher;
    std::weak_ptr<Person> wp = teacher;

    if (auto temp = wp.lock())
        std::cout<< temp-> Name; //  Jack
    
    // coach is reset
    coach.reset();

    // teacher is reset to Rose
    teacher.reset(new Person("Rose"));

    if (wp.expired()) // true
        std::cout<< "The old teacher is not there."; 
}