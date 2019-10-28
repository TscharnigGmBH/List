#define NULL (void *) 0

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


struct node {

    int value;
    struct node* next;

};

void append(struct node* head, int x) {

    struct node* current = head;
    while (current->next != NULL) {

        current = current->next;

    }
    current->next = malloc(sizeof(struct node*));
    current->next->value = x;
}

void initialize(struct node* head, int x) {

    head->value = x;
    head->next = NULL;

}

void printList(struct node* list) {
    struct node* current = list;

    while (current->next != NULL) {

        printf("%d\n", current->value);
        current=current->next;


    }
    if (current->next == NULL) {
        printf("%d", current->value);
    }
}

void inputList(struct node* head) {

    char wh = 'j';
    int x = 0;

    do {

        printf("> ");
        scanf("%d", &x);
        printf("\nAgain? (j/n) >");
        scanf("%c", &wh);
        append(head, x);

    } while (wh == 'j');

}

int main() {
    struct node head;
    initialize(&head, 1);
    inputList(&head);

    printList(&head);

    return 0;
}