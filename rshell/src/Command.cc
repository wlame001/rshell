#include "Command.h"
#include <sstream>
#include <boost/tokenizer.hpp>

using namespace std;

void Command::print(){
    for(int i = 0; i < args.size();i++)
        cout << "args[" << i << "]: " << args.at(i) << endl;
}

Command::Command(){}
Command::Command(std::string s) : Word(s){
    stringstream ss(s);
    ss >> exec; // exec holds the executable
    run();
}
virtual void Command::run(){
    //break up command into smaller commands
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep(" ");
    tokenizer tokens(this->data, sep);
    for (tokenizer::iterator tok = tokens.begin(); tok != tokens.end(); ++tok){
        char *k = new char[tok->size() + 1];
        for(int i = 0; i < tok->size(); i++)
           k[i] = tok->at(i);
        k[tok->size()] = '\0';
        args.push_back(k);
    }
    args.push_back('\0');
}



// int main(){
    
//     string k = "ls -h && echo helloworld # asuh dude";
//     char* arg[k.size() + 1];
    
//     return 0;
// }
