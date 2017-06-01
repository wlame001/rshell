#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>


class Order{
    
    public:
    std::vector<std::string> order;
    
    Order(std::string str){
        split(str);
        removeParenthesis();
    }
    
     void removeExtraSpaces(std::string & str){
        if(!str.empty()){
            if(str.at(0) == ' ')
                str.erase(0,1);
            if(str.at(str.size()-1) == ' ' && !str.empty())
                str.erase(str.size()-1,1);
            return;    
        }
        
     }

    
    void removeParenthesis(){ // maybe dont call findConnectors on 1st
        for(unsigned i = 0; i < this->order.size(); i++){
            boost::erase_all(this->order.at(i), "(");
            boost::erase_all(this->order.at(i), ")");
            removeExtraSpaces(this->order.at(i));
            if(this->order.at(i).empty()){
                this->order.erase(this->order.begin() + i,this->order.begin() + i + 1);
                i--;
            }    
            findConnectors(this->order.at(i));    
        }
        
    }
    // just searches string for connectors and moves to start if necessary
    void findConnectors(std::string & str){
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

    void replaceConnectors(std::string & str, int i, int length){
        std::string con = str.substr(i + 1, length);
        con += " ";
        str = str.substr(0, i);
        str = str.insert(0, con);
    }
    
    void split(std::string str){
        // helper variables to keep track of deepest set
        unsigned currentDepth = 0, maxDepth = 0, deepestClosed = -1, deepestOpen = -1; 
        
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
    
    void print(){
        for (unsigned i = 0; i < order.size(); i++){
            std::cout << "order[" << i <<  "] = "<< order.at(i) << std::endl;
        }
    }
};

int main(){
    
    //std::string k = "(test -e test/file/path || (echo helloworld)) || echo helloworld2";
    std::string k = "(echo A && echo B) || (echo C && echo D) && (echo E)";
    
    Order * ord = new Order(k);
    ord->print();

    
    return 0;
}