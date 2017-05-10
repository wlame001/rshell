#ifndef WORD_H
#define WORD_H

#include "Word.h"
#include <vector>

class Command : public Word {
    
    protected:
    string exec;
    char connector = ';'; // defualt to ; , can be & for && and | for ||
    vector<char*> args; // contains executable followed by arguments, ex: ls, -a
    
    public:
    void print(); // prints contents of args
    Command();
    Command(std::string s);
    virtual void run();
};

#endif