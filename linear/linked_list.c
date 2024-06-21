#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int data;
  struct NODE *next;
} node;


void add_last(node **cur, int data) {
    node *temp = malloc(sizeof(node));
    
    temp->data = data;
    temp->next = NULL;
    (*cur)->next = temp;
    
    *cur = temp;
}

void add_first(node **head, int data) {
    node *temp = malloc(sizeof(node));
    
    temp->data = data;
    temp->next = *head;
    
    *head = temp;
}

void show(node *root) {
    while(root) {
      printf("%i\n", root->data);
      root = root->next;
    }
}

void free_list(node **head) {
  while(*head) {
      node *temp;
      temp = (*head)->next;
      free(*head);
      *head = temp;
  }
}

int get_len(node *head) {
  int count = 0;
  
  while(head) { 
    count++;
    head = head->next;
  }
  return count;
}

void add_pos(node **head, int pos, int data) {
    node *temp = malloc(sizeof(node));
    node *cur = *head;
    temp->data = data;
    
    if(pos >= get_len(cur)) {
      for(int i = 1; i < pos - 1; i++) {
        cur = cur->next;
      }
      
      temp->next = cur->next;
      cur->next = temp;
    }
    
    else {
      printf("invaid index\n");
    }
}

int main() {
  node *head = malloc(sizeof(node));
  head->data = 0;
  head->next = NULL;
  
  node *cur;
  cur = head;
  add_last(&cur, 1);
  add_pos(&head, 2, 2);
  show(&head);
  
  free_list(&head);
  
  return 0;
}
