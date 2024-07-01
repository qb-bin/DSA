#include <stdio.h>
#include <stdio.h>

typedef struct NODE {
    int data;
    struct NODE *next;
    struct NODe *back;
} node;

node* new_node() {
    return (node *)malloc(sizeof(node));
}

node* new_list() {
    return new_node();
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

void append(node *tail, int data) {
    node *temp =  new_node();
    temp->data = data;
    temp->back = tail;
    tail->next = temp;
    temp->next = NULL;
}

int max(node *head){
    int max = head->data;
    while(head != NULL){
        if(head->data > max){
            max = head->data;
        }
        head = head->next;
    }
    return max;
}

int min(node *head){
    int min = head->data;
    while(head != NULL){
        if(head->data < min){
            min = head->data;
        }
        head = head->next;
    }
    return min;
}

void print_forward(node *head) {
    while(head != NULL) {
      printf("%i\n", head->data);
      head = head->next;
    }
}

void print_backward(node *tail) {
    while (tail != NULL) {
        printf("%i\n", tail->data);
        tail = tail->back;
    }
}

void get(node *head,int index){
    node *cur = head;
    for(int i=0 ; i<index ; i++){
        cur = cur->next;
    }
    if(cur == NULL){
        printf("index is out of range");
    }
    else{
        printf("%d",cur->data);
    }
}

void search(node *head,int data){
  int key = data;
  int a=0;
  node *cur= head;
  while(cur != NULL){
    if(cur->data == key){
      printf("index: %d",a);
      return;
    }
    cur = cur->next;
    a++;
  }
  if(cur == NULL){
      printf("given data is not found");
  }
}
