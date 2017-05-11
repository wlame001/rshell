#ifndef INTERFACE_H
#define INTERFACE_H


#include "../header/Command.h"


class Interface : public Command {
    
    protected :
    std::vector <Command> cmd;
    /*
    Helper function of split, iterates through data and sets each Command's 
    connector field corresponding to the correct connector used
    Also checks if the user entered 1 or 2 of the appropriate connector type
    & is an error while && is correct, etc..
    */
    void con();
    
    
    public:
    /*
    prints contents of cmd
    */
    void print();

    /*
    Uitlizes the tokenizer function to pass through data and split it into 
    different commands based on the location of the connectors
    */
    void split();
    
    void exit_fn(int i){
        exit(i);
    }
    
    Interface(std::string s);
    
    /*
    This function is called by main, it creates appropriate processes through
    fork, and pipes the process so that it is known if the last statement 
    taken in was executed. Then calls the desired functions through execvp 
    and returns
    */
    virtual void run();
    
};

#endif