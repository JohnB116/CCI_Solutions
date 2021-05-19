/* #3: Remove a middle node from as singly-linked list

    The function that performs this 
    operation can be found in the singly linked list header file
    in this directory.

    This command line arguments consist of the elements of the list followed
    by the index of the element to remove.

*/
#include <iostream>
#include "single_list.h"

int main(int argc, char * argv[]){

    single_list<int> the_list;
    for(int i = 1; i < argc - 1; i++){
        the_list.push_back(atoi(argv[i]));
    }

    single_list_node<int> * x = the_list.start();
    for(int i = 0; i < the_list.get_size(); i++){
        std::cout << x->value << "->";
        x = x->next;
    }
    std::cout << "\n";
    
    single_list_node<int> * itr1 = the_list.start();
    single_list_node<int> * itr2 = the_list.start();
    itr2 = itr2->next;

    int idx = atoi(argv[argc-1]);
    std::cout << "Index is " << idx << std::endl;
    for(int i = 0; i < idx-1; i++){
        itr1 = itr1->next;
        itr2 = itr2->next;
    }

    single_list_node<int> * to_remove = itr1->next;
    itr1->next = itr2->next;

    delete to_remove;

    x = the_list.start();
    for(int i = 0; i < the_list.get_size() - 1; i++){
        std::cout << x->value << "->";
        x = x->next;
    }

    std::cout << "\n";

    return 0;
}
