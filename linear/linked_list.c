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

int MAX(node *head){
    int max = head->data;
    while(head != NULL){
        if(head->data > max){
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

int MIN(node *head){
    int min = head->data;
    while(head != NULL){
        if(head->data < min){
            min = head->data;
        }
        head = head->next;
    }
    return min;
}

void show(node *head) {
    while(head != NULL) {
      printf("%i\n", head->data);
      head = head->next;
    }
}
