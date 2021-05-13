/* #1: Remove duplicates from a linked list

    For simplicity's sake, I know my way around linked
    lists fairly well, so I will just use the standard template library
    for these problems that I see can use it.

    In this case we are working with a linked list of integers.
    Iterating through the linked list is O(n). Looking up values
    in the hash table to find duplicates is O(1) for n elements.
    A removal from the list is an O(1) operation.
    This is an O(3n) = O(n) algorithm as a whole.

*/
#include <iostream>
#include <unordered_map>
#include <list>
#include <iterator>

int main(int argc, char * argv[]){

    std::unordered_map<int, char> comparator;
    std::list<int> the_list;

    //Insert proper values into 
    //list and hash table
    for(int i = 1; i < argc; i++){
        the_list.push_back(atoi(argv[i]));
        comparator.insert(std::make_pair(atoi(argv[i]), 0));
    }
    for(auto i : the_list){
        std::cout << i << "->";
        comparator.insert(std::make_pair(i, ++comparator[i]));
    }

    //Iterate throught the list, look up each
    //element in the hash table, and
    //remove the element if it is already in the hash
    //table as a non-zero value
    std::list<int>::iterator itr = the_list.begin();

    while(itr != the_list.end()){
        if(comparator[*itr] > 1){
            int val = *itr;
            itr = the_list.erase(itr);
            comparator.insert(std::make_pair(val, --comparator[val]));
            itr++;
        }
        itr++;
    }

    std::cout << std::endl;

    for(auto x : the_list){
        std::cout << x << "->";
    }

    std::cout << std::endl;

    return 0;
}
