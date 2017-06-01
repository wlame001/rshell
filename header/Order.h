#ifndef ORDER_H
#define ORDER_H

#include "Word.h"
#include <vector>

class Order : public Word {

    public:
    
    std::vector<std::string> order;
    
    Order(){};
    
    Order(std::string);
    
    void split(std::string);
    
    void findConnectors(std::string & );
    
    void removeExtraSpaces(std::string & );
    
    void replaceConnectors(std::string & , int , int );
    
    void combine();
    
    void remove();
    
    virtual bool run();
    
    void print();
    
};

#endif //ORDER_H