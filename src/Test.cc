#include "../header/Test.h"
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../header/Interface.h"

void Test::set_flag(int f){
    this->flag = f;
}

int Test::get_flag(){
    return this->flag;
}

// flag -e = 1, -f = 2, -d = 3
Test::Test(Command c): Command(){
    this->exec = c.get_exec();
    this->args = c.args;
    this->connector = c.get_connector();
    flagTest();
    //test to
}

void Test::flagTest(){
    if(strcmp(this->args.at(1), "-e") == 0)
        set_flag(1);
    else if(strcmp(this->args.at(1), "-f") == 0)
        set_flag(2);
    else if(strcmp(this->args.at(1), "-d") == 0)
        set_flag(3);
    else{
        //std::cout << std::endl << "before: args.at(1) is " << args.at(1) << std::endl;
        char k[] = "-e";
        args.insert(args.begin() + 1, k);
        set_flag(1);
        //std::cout << "**set args.at(1) to " << args.at(1) << std::endl;
    }
    
}

void Test::print(){
    //std::cout << this->get_exec() << std::endl;
    std::cout << "calling print: ";
    Command::print();
}

bool Test::check_directory(){
    struct stat st;
    //if(S_ISDIR(st.st_mode))
    if(stat(args.at(2), &st) == 0 && S_ISDIR(st.st_mode)){
        std::cout << "(True)" << std::endl;
        return true;
    }    
    else
        std::cout << "(False)" << std::endl;
    return false;
    
}

bool Test::check_reg_file(){
    struct stat st;
    if(stat(args.at(2), &st) == 0 && S_ISREG(st.st_mode)){
        std::cout << "(True)" << std::endl;
        //this->was_exe
        return true;
    }
    else
        std::cout << "(False)" << std::endl;
    return false;
}

bool Test::check_both(){
    if(check_directory() && check_reg_file()){
        std::cout << "(True)" << std::endl;
        return true;
    }    
    else
        std::cout << "(False)" << std::endl;
    return false;
}

bool Test::run(){
    bool ret;
    DIR *dir = opendir(args.at(2));
    //struct dirent  *dp;
    if(this->get_flag() == 1)
        ret = check_directory();
    else if(this->get_flag() == 2)
        ret = check_reg_file();
    else if (this->get_flag() == 3)
        ret = check_both();
        
    closedir(dir);
    
    return ret;
}
