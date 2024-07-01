#include <stdio.h>
#include <stdio.h>

typedef struct NODE {
    int data;
    struct NODE *next;
    struct NODe *back;
} node;

node* new_list() {
    return (node *)malloc(sizeof(node));
}

int free_list(node *head) {
    node *temp_ptr;
    int tracker = 0;
    
    while(head) {
        temp_ptr = head->next;
        free(head);
        head = temp_ptr;
        tracker++;
    }
    
    return tracker;
}

int main() {
    return 0;
}
