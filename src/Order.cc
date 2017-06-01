#include "../header/Order.h"
#include <boost/algorithm/string.hpp>

Order::Order(std::string str): Word(str){
    if(str != ""){
        this->split(this->get_data());
        this->remove();
        this->combine();
    }
}



void Order::split(std::string str){
// helper variables to keep track of deepest set
    unsigned currentDepth = 0, maxDepth = 0;
    int deepestClosed = -1, deepestOpen = -1; 
    for(unsigned i = 0; i < str.size(); i++){
        if(str.at(i) == '(' ){
            currentDepth++;
            if(currentDepth > maxDepth){
                deepestOpen = i;
                maxDepth = currentDepth;
            }
        }    
        if(str.at(i) == ')'){
            if(currentDepth == maxDepth){
                deepestClosed = i;
                maxDepth = currentDepth;
            }
            currentDepth--;
        }    
    }
    if(deepestOpen == -1 && deepestClosed == -1){//base case
        this->order.push_back(str);
        return;
    }    
    this->order.push_back(str.substr(deepestOpen, deepestClosed - deepestOpen + 1));
    str.erase(deepestOpen, deepestClosed - deepestOpen + 1);
    split(str);
}



void Order::findConnectors(std::string & str){
    unsigned found1 = str.find(" ||");
    unsigned found2 = str.find(" &&");
    unsigned found3 = str.find(" ;");
    unsigned sz = str.size();
    
    if(found1 == sz - 3 || found2 == sz - 3 || found3 == sz - 2){
        if(found1 < sz) // " ||" was found
            replaceConnectors(str, found1, 3);
        else if(found2 < sz)// " &&" was found
            replaceConnectors(str, found2, 3);
        else if(found3 < sz)// " ;" was found
            replaceConnectors(str, found3, 2);
    }   
}


    
void Order::removeExtraSpaces(std::string & str){
    if(!str.empty()){
        if(str.at(0) == ' ')
            str.erase(0,1);
        if(str.at(str.size()-1) == ' ' && !str.empty())
            str.erase(str.size()-1,1);
        return;    
    }
    
}

void Order::combine(){
    std::string ret;
    for(unsigned i = 0; i < this->order.size(); i++){
        ret += this->order.at(i);
        if (i < this->order.size() - 1)
            ret += " ";
    }
    this->set_data(ret);
}

void Order::remove(){ // maybe dont call findConnectors on 1st
    for(unsigned i = 0; i < this->order.size(); i++){
        boost::erase_all(this->order.at(i), "(");// remove parentheses
        boost::erase_all(this->order.at(i), ")");
        removeExtraSpaces(this->order.at(i)); // remove spaces
        if(this->order.at(i).empty()){ // remove empty strings from vector
            this->order.erase(this->order.begin() + i,this->order.begin() + i + 1);
            i--;
        }    
        findConnectors(this->order.at(i)); // properly order connectors
    }
    
}


void Order::replaceConnectors(std::string & str, int i, int length){
    std::string con = str.substr(i + 1, length);
    con += " ";
    str = str.substr(0, i);
    str = str.insert(0, con);
}

void Order::print(){
    for (unsigned i = 0; i < order.size(); i++){
        std::cout << "order[" << i <<  "] = "<< order.at(i) << std::endl;
    }
    std::cout << "data: " << this->get_data() << std::endl;
}

bool Order::run(){
    return true;
}