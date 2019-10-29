#define NULL ((void *) 0)

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


struct node {
    int value;
    struct node* next;
};

void inputList(struct node* head);
void append(struct node* head, int x);
void initialize(struct node* head, int x);
void printList(struct node* list);
void pop(struct node* list);
void push(struct node* list, int value);
int get(struct node *list, int index);
int length(struct node* list);

// todo: insert on index
// todo: delete on index
// todo: delete on beginning
// todo: time comparison with array

int main() {
    struct node head;
    initialize(&head, 0);
    inputList(&head);
    printf("\n%d", length(&head));
    printf("\n%d", get(&head, 0));

    return 0;
}

void append(struct node* head, int x) {
    // Works
    // struct node* current = head;
    // First used current instead of head, but it has the same result
    while (head->next != NULL) {
        head = head->next;
    }

    head->next = (struct node*)malloc(sizeof(struct node*));
    head->next->value = x;
}

void initialize(struct node* head, int x) {
    // Works
    head->value = x;
    head->next = NULL;
    // you have to do it, when you don't call it, you will get an error
}

void printList(struct node* list) {
    // Works
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
    // Works
    // char wh = 'j';
    // int count = 0;
    int x = 0;

    do {
        printf("> ");
        scanf("%d", &x);
        // printf("\nAgain? (j/n) >");
        // scanf(" %c", &wh);
        if (x != 0) {
            append(head, x);
        }
    } while (x != 0);
    // Works, had to add a space in front of %c
}

void pop(struct node* list) {
    // Works
    while (list->next->next != NULL) {
        list = list->next;
    }
    list->next->next = NULL;
    list->next->value = NULL;
    list->next = NULL;

}

void push(struct node* list, int value) {
    // todo: doesn't change anything in the lsit
    // Push means, insert on beginning
    // Doesn't do any change to the list
    struct node* head = malloc(sizeof(struct node*));
    head->next = list;
    head->value = value;
    list = head;
}

int get(struct node *list, int index) {
    // todo: make it recursion
    int i = 0;
    if (index > length(list)) {
        fprintf(stderr, "\nOutofBounce\n");
        exit(-1);
    } else {
        for (i = 0; i < index; i += 1) {
            list = list->next;
        }
        return list->value;
    }
}

int length(struct node* list) {
    // Works
    if (list->next == NULL) {
        return 1;
    } else {
        return 1+length(list->next);
    }

}