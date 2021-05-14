/* #2: Find the k-th to last element in a singly-linked list

    For this I created a singly-linked list class to go more
    in-depth with this solution, which can be found in 'single_list.h'
    It makes the list out of the first elements, and the last element
    serves as the 'k' value.
    This is an O(n) algorithm.

*/
#include <iostream>
#include "single_list.h"

int main(int argc, char * argv[]){

    single_list<int> the_list;
    
    for(int i = 1; i < argc - 1; i++){
        the_list.push_back(atoi(argv[i]));
    }
    
    //Using a list node as an iterator
    single_list_node<int> * itr = the_list.start();
    for(int i = 0; i < the_list.get_size() - 
        atoi(argv[the_list.get_size() + 1]); i++){
        itr = itr->next;
    }

    std::cout << itr->value << std::endl;
    

    return 0;
}
