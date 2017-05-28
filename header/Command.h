#ifndef COMMAND_H
#define COMMAND_H

#include "Word.h"
#include <vector>

class Command : public Word {
    
    protected:
    std::string exec;
    char connector = ';'; // defualt to ; , can be & for && and | for ||
    
    public:
    std::vector<char*> args; // contains executable followed by arguments, ex: ls, -a
    void set_connector(char k){
        connector = k;
    }
    char get_connector(){
       return connector; 
    }
    void set_exec(std::string s){
        exec = s;
    }
    
    std::string get_exec();
    
    void print(); // prints contents of args
    
    Command();
    
    Command(std::string s);
    
    void stringToChar(char* &, std::string);// converts the string passed in to the char*
    
    virtual void run();
};

#endif