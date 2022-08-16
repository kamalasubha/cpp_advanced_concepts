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
    
    A->goalKeeper = B;
    B->team = A;

    std::cout<<"A use count: "<<A.use_count()<<std::endl;
    std::cout<<"B use count: "<<B.use_count()<<std::endl;
    
    return 0;

}