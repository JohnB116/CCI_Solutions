/* #3: Replace all spaces in a string with 
       '%20'

       This is a solution that allows some abstraction. I am thinking
       I might rewrite the solution in C to demonstrate a more basic 
       implementation.

*/
#include <iostream>
#include <iterator>
#include <string>

int main(int argc, char * argv[]){

    //Construct string from command line arguments
    std::string res = "";
    res.append(argv[1]);

    for(int i = 2; i < argc; i++){
        res.append(" ");
        res.append(argv[i]);
    }

    std::cout << res << std::endl;
    int count = res.length();

    for(int i = 0; i < count; i++){
        if(res[i] == ' '){
            res.erase(i, 1);
            res.insert(i, "%20");
        }
    }

    std::cout << res << std::endl;

    return 0;
}