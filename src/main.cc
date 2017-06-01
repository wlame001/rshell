#include "../header/Order.h"
#include "../header/Interface.h"

using namespace std;

bool parenthesesCheck(std::string str){
    unsigned numClosed = 0;
    unsigned numOpen = 0;
    for(unsigned i = 0; i < str.size(); i++){
        
        if(str.at(i) == '(')
            numOpen++;
        else if (str.at(i) == ')')    
            numClosed++;
    }
    if(numOpen != numClosed){
        std::cout << "incorrect number of parentheses" << std::endl;
        return false;
    }    
    return true;
}


int main(){

    std::string input;
    std::cout << "input enter 'exit' to quit" << std::endl;
    while  (!cin.eof()){
            std::cout << "$ ";
        getline(std::cin, input);
        if(input == "")
            break;
        if(!parenthesesCheck(input))
            exit(-1);
        Order * ord = new Order(input);
        Interface * interface = new Interface(ord->get_data());
        interface->run();
    }
    return 0;
}