#ifndef WORD_H
#define WORD_H

#include <iostream>
#include "../src/Base.cc"

class Word : public Base {
        public:
        std::string data;
        
        
        void comment(std::string &str){
        unsigned i = str.find("#");
        if ( i < str.size())
            str = str.substr(0,i);
        }
        
        
        Word(){}
        Word(std::string s){
            comment(s);
            data = s;
            
        }
        
        std::string get_data(){ 
            return data;
        }
        
        void print(){
            std::cout << data;
        }
        virtual void run() = 0;
};

#endif