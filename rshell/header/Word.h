#ifndef WORD_H
#define WORD_H

#include "Base.cc"
#include <iostream>

class Word : public Base {
        public:
        std::string data;
        
        
        void comment(std::string &str){
        int i = str.find("#");
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
        
        virtual void run() {
            return;
        }
};

#endif