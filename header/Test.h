#ifndef TEST_H
#define TEST_H
#include "Command.h"


class Test : public Command {
    
    protected:
    
    int flag;
    
    public:
    
    Test();
    
    Test(Command); //will be made from 
    
    void print();
    
    int get_flag();
    
    void set_flag(int);
    
    void flagTest();
    
    bool check_directory();
    
    bool check_reg_file();
    
    bool check_both();
    
    virtual bool run();

};

#endif