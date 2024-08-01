#include <iostream>

using namespace std;


struct ListEntry {
    int value;
    struct ListEntry *next;
};


int main() {

   
    struct ListEntry last = {30, NULL};

    struct ListEntry second = {20, &last};

    struct ListEntry head = {10, &second};


    struct ListEntry *current = &head;

    while(true) {
        if(current->next == NULL) {
            printf("Tail node reached. Value %d\n", current->value);
            break;
        }

        printf("Linked list element %d\n", current->value);
        current = current->next;

    }



}



