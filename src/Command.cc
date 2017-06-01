#include "../header/Command.h"
#include <sstream>
#include <boost/tokenizer.hpp>

using namespace std;

void Command::print(){
    for(unsigned i = 0; i < args.size(); i++)
        cout << "args[" << i << "]: " << args.at(i) << endl;
}

string Command::get_exec(){
    return this->exec;
}

Command::Command(){}
Command::Command(std::string s) : Word(s){
    stringstream ss(s);
    ss >> exec; // exec holds the executable
    run();
}

void Command::stringToChar(char* &c, string s ){
    unsigned i;
    for( i = 0; i < s.size(); i++)
        c[i] = s.at(i);
    i++;    
    c[i] = '\0'; 
}

//break up command into smaller commands
bool Command::run(){
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep(" ");
    tokenizer tokens(this->data, sep);
    for (tokenizer::iterator tok = tokens.begin(); tok != tokens.end(); ++tok){
        char *k = new char[tok->size() + 1];
        stringToChar(k, *tok);
        args.push_back(k);
    }
    args.push_back('\0');
    return true;
}
