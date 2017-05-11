#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "../header/Interface.h"
#include <boost/tokenizer.hpp>

//see header file for more detailed comments on how these functions operate
void Interface::print(){
    for (unsigned i = 0; i < cmd.size(); i++){
        std::cout << "cmd[" << i << "]: "<< cmd.at(i).data << ", exec: ";
        std::cout << "connector: " << cmd.at(i).get_connector() << std::endl;
    }
}
    
void Interface::con(){
    int k = 0;
    for (unsigned i = 0; i < this->data.size(); i++){
        if (this->data.at(i) == ';') k++;
        else if (this->data.at(i) == '&'){
            if(i < this->data.size()- 1 && this->data.at(i + 1)  == '&'){
                k++;
                i++;
                cmd.at(k).set_connector('&');
            }    
            else { 
                std::cout << "Invalid connector input, exiting now. " << std::endl;
                exit_fn(-1);
            }    
        }
        else if (this->data.at(i) == '|'){
            if(i < this->data.size()- 1 && this->data.at(i + 1)  == '|'){
                k++;
                i++;
                cmd.at(k).set_connector('|');
            }    
            else { 
                std::cout << "Invalid connector input, exiting now. " << std::endl;
                exit_fn(-1);
            }     
        } 
    }
}

void Interface::split(){
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep(";|&");
    tokenizer tokens(this->data, sep);
    for (tokenizer::iterator tok = tokens.begin(); tok != tokens.end(); ++tok){
        cmd.push_back(Command(*tok));
        cmd.at(cmd.size()-1).data.push_back('\0');
        if(cmd.at(cmd.size()-1).data.at(0) == ' ')
            cmd.at(cmd.size()-1).data.replace(0,1,"");
    }
    con();
    
}


Interface::Interface(std::string s){
    //comment(this->data);
    this->data = s;
    
    split();
}

void Interface::run(){
    pid_t child_pid, tpid;
    int child_status;
    int fd[2];
    int was_executed = 1;//stores value on whether previous command was executed
    if(pipe(fd) == -1) // check perror
        perror("pipe");
    for (unsigned i = 0; i < cmd.size(); i++){// error in creating a child
        child_pid = fork();// check perror
        if(child_pid == -1){
            std::cout << "Couldnt create a child";
            perror("fork failed");
        }
        else if(child_pid == 0){ // child process, writing
            close(fd[0]); // fd[0] is for reading
            
            // statement makes sure this command is supposed to executed based
            // on whether the previous command was executed or not
            if((i == 0) || 
            (cmd.at(i).get_connector() == '|' && was_executed == 0)|| 
            (cmd.at(i).get_connector() == '&' && was_executed == 1)||
            (cmd.at(i).get_connector() == ';')){
                
                if(strcmp(cmd.at(i).args.at(0), "exit" ) == 0) 
                    exit_fn(0);
                    
                char **command = &(cmd.at(i).args.at(0));
                execvp(cmd.at(i).get_exec().c_str(), command); // execute
            }
                was_executed = 0; //execution failed
                write(fd[1], &was_executed, sizeof(was_executed));// check perror
                exit_fn(0);
            
        }
        else{ // parent process, reading from pipe
            close(fd[1]);// fd[1] is for writing
            read(fd[0], &was_executed, sizeof(was_executed));
            tpid = waitpid( child_pid, &child_status, WCONTINUED);// check perror
            if(tpid == -1){
                perror("waitpid");
                exit_fn(-1);
            } 
            while (tpid != child_pid){// wait for the child command to finish
                //cout << "got here";
            }
        }
    }// brace forloop
} 
