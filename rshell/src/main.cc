#include <iostream>

#include <stdlib.h>
#include "Base.cc"
#include "Word.h"
#include "Command.h"


int main() {
    
    //Word* w = new Word("test word");
    //std::cout << w->get_name() << std::endl;
    std::string input;
    
    
    
    // change loop to a do while
    while (input != "exit" && input != "0"){
        std::cout << "$ ";
        getline(std::cin, input);
        std::cout << "Entered: " << input << std::endl;
        Command* com = new Command(input);
        std::cout << "calling run ";
        com->run();
    }
    
    fork();
    std::cout << "hello world" << std::endl;
    return 0;
    
}