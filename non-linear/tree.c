#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *parent;
    struct node *left;    
    struct node *right;
} node;

node root;
node *cur;

void add_right() {
    node *temp = malloc(sizeof(node));
    temp->parent = cur;
    temp->left = NULL;
    temp->right = NULL;
    cur->right = temp;
}

void add_left() {
    node *temp = malloc(sizeof(node));
    temp->parent = cur;
    temp->left = NULL;
    temp->right = NULL;
    cur->left = temp;
}

void move_left() {
    if(cur->left == NULL) {
        printf("no left\n");
    } else {
        cur = cur->left;
    }
}

void move_right() {
    if(cur->right == NULL) {
        printf("no right\n");
    } else  {
        cur = cur->right;
    }
}

void move_back() {
    if( cur->parent == NULL) {
        printf("root node\n");
    } else {
        cur = cur->parent;
    }
}

void print() {
    printf("data:%i\nleft: %i\nright: %i\n", cur->data, cur->left, cur->right);
}

void insert() {
    int data;
    printf("val: ");
    scanf("%i", &data);
    cur->data = data;
}

void delete() {
    free(cur);
}

int main () {
    root.data = 9;
    cur = &root;
    int option = 0;
    printf("1:mov-left\n2:mov-right\n3:mov-back\n4:aleft\n5:aright\n6:print\n7:insert\n8:delete\n");
    while(1) {
        printf("input:");
        scanf("%i", &option);
        switch(option) {
            case 1:
                move_left();
                option = 0;
                break;
            case 2:
                move_right();
                option = 0;
                break;
            case 3:
                move_back();
                option = 0;
                break;
            case 4:
                add_left();
                option = 0;
                break;
            case 5:
                add_right();
                option = 0;
                break;
            case 6:
                print();
                option = 0;
                break;
            case 7:
                insert();
                option = 0;
                break;
            case 8:
                delete();
                option = 0;
                break;
        }
    }
    
    return 0;
}