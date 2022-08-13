#include <iostream>
#include <memory>

struct Person;

struct Team{
    std::shared_ptr<Person> goalKeeper;
    ~Team(){std::cout<<"Team destructed.";}
};
struct Person{
    std::shared_ptr<Team> team;
    ~Person(){std::cout<<"Person destructed.";}
};

int main(){
    
    
    auto A = std::make_shared<Team>();
    auto B = std::make_shared<Person>();
    auto C = std::make_unique<Person>();
    
    A->goalKeeper = B;
    B->team = A;
    
    return 0;

}