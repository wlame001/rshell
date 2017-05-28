#ifndef TEST_H
#define TEST_H
#include "Command.h"

class Test : public Command {
    
    public:
    
    Test();
    
    Test(Command); //will be made from 
    
    void print();
    
    void flagTest()
    
    virtual void run(){
        
    }

};

#endif