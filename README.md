# rshell
The program functions by taking in input and doing a two-pass parsing method to split the commands up first by connectors, then by spaces. 
As for structure I used a composite design pattern with my final Interface class inheriting from a Command class. The Command class Consists of individual commands, for example if the user entered a complex statement such as "ls -a && echo helloworld", one command would be "ls -a" and the another seperate command would be "echo helloworld". These two commands would be linked together by the Interface class' vector of Commands called cmd. The Interface class and the Command class's main processes occur in their respective virtual void run functions. Both of these classes inherit from the Word class which has a single string field and this class in turn inherits from an abstract base class called base.

# known bugs
There are a few errors/warnings that one will immediately notice if you dont compile with the --std=c++11 setting. 
A few other bugs or at least undesireables are that some of the class fields are not protected when they should be. Instead they were moved to public to make testing a bit easier.
There are other bugs out there lurking, waiting to be squashed.
Some inefficiencies exists in the Command class due to using vector<char*> instead of using char*[], and using the stringstream class aswell as the boost tokenizer class when im sure one would have done the job. 
