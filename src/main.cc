#include "../header/Interface.h"

using namespace std;

int main() {

    std::string input;
    std::cout << "input enter 'exit' to quit" << std::endl;
    while  (!cin.eof()){
        std::cout << "$ ";
        getline(std::cin, input);
        Interface* interface = new Interface(input);
        interface->run();
    }
    return 0;
    
}