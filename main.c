#define NULL (void *) 0

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


struct node {
    int value;
    struct node* next;
};

void append(struct node* head, int x) {
    // struct node* current = head;
    // First used current instead of head, but it has the same result
    while (head->next != NULL) {
        head = head->next;
    }

    head->next = malloc(sizeof(struct node*));
    head->next->value = x;
}

void initialize(struct node* head, int x) {
    head->value = x;
    head->next = NULL;
    // you have to do it, when you don't call it, you will get an error
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
    int count = 0;

    do {
        printf("> ");
        scanf("%d", &x);
        printf("\nAgain? (j/n) >");
        scanf(" %c", &wh);
        append(head, x);
    } while (wh == 'j');
    // Works, had to add a space in front of %c
}

// todo: pop (delete last element)
// todo: insert on index
// todo: insert on beginning
// todo: delete on index
// todo: delete on beginning
// todo: get item on index
// todo: time comparison with array

int main() {
    struct node head;
    initialize(&head, 1);
    inputList(&head);
    printList(&head);

    return 0;
}