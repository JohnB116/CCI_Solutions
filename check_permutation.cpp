/* #2: Check if 2 strings are permutations of each other
       
       Again, I used a hash table to solve this problem, which will give 
       a runtime complexity of O(n)
*/
#include <iostream>
#include <string>
#include <iterator>
#include <unordered_map>

int main(int argc, char * argv[]){

    //Once again using a hash table
    std::string str1 = argv[1],
    str2 = argv[2];
    std::unordered_map<char, int> comparator;

    //Strings must be of equal length
    if(str1.length() != str2.length()){
        std::cout << "Strings are not permutations\n";
    }

    else{
        //Insert character counts into hash table
        for(int i = 0; i < str1.length(); i++){
            comparator.insert(std::make_pair(str1[i], 0));
        }

        for(auto i : str1){
            comparator.insert(std::make_pair(i, ++comparator[i]));
        }

        //Now compare str2
        for(auto i : str2){
            //Mismatch is found, break
            if(comparator.find(i) == comparator.end() || 
            comparator[i] < 1){
                std::cout << "Strings are not permutations\n";
                exit(0);
            }
            else{
                comparator.insert(std::make_pair(i, --comparator[i]));
            }
        }

        std::cout << "The strings are permutations of each other\n";
    }

    return 0;
}