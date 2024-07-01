#include <stdio.h>

typedef struct NODE {
    int data;
    struct NODE *next;
    struct NODe *back;
} node;

node* new_list() {
    return (node *)malloc(sizeof(node));
}

int main() {
    return 0;
}
