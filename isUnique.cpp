/*  Problem 1: Determine if a string is composed of 
    unique characters.

    For this I used a hash-table based solution, 
    it ensures O(1) operations when checking that characters have not 
    already been used, thus leading to an O(n) solution for n characters in a string.
    This may not provide optimal space complexity, but it will provide optimal time 
    complexity.

    This solution assumes that the use of abstract data structures is allowed.
*/

#include <iostream>
#include <string>
#include <iterator>
#include <unordered_map>

int main(int argc, char * argv[]){

    std::string str = argv[1];
    std::unordered_map<char, int> comparator;

    for(int i = 0; i < str.length(); i++){
        if(comparator.find(str[i]) != comparator.end()){
            std::cout << "Not unique\n";
            exit(0);
        }
        comparator[str[i]] = i;
    }

    std::cout << "Unique\n";

    return 0;
}