#include "../header/Test.h"


Test::Test(Command c): Command(){
    this->exec = c.get_exec();
    this->args = c.args;
    this->connector = c.get_connector();
    
    //test to
}

void Test::flagTest(){
    
}

void Test::print(){
    //std::cout << this->get_exec() << std::endl;
    std::cout << "calling print: ";
    Command::print();
}