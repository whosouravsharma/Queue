#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *prev, *next;
};

struct node *head = NULL, *tail = NULL;

struct node * createNode(int info) {
    struct node *new = (struct node *)malloc(sizeof (struct node));
    new->info = info;
    new->next = new->prev = NULL;
    return (new);
}

void create() {
    head = createNode(0);
    tail = createNode(0);
    head->next = tail;
    tail->prev = head;
}

void addAtFront(int info) {
    struct node *new, *temp;
    new = createNode(info);
    temp = head->next;
    head->next = new;
    new->prev = head;
    new->next = temp;
    temp->prev = new;
}


void addAtRear(int info) {
    struct node *new, *temp;
    new = createNode(info);
    temp = tail->prev;
    tail->prev = new;
    new->next = tail;
    new->prev = temp;
    temp->next = new;
}
void deleteAtFront() {
    struct node *temp;
    if (head->next == tail) {
            printf("Queue is empty\n");
    } else {
            temp = head->next;
            head->next = temp->next;
            temp->next->prev = head;
            free(temp);
    }
    return;
}
void deleteAtRear()  {
    struct node *temp;
    if (tail->prev == head) {
            printf("Queue is empty\n");
    } else {
            temp = tail->prev;
            tail->prev = temp->prev;
            temp->prev->next = tail;
            free(temp);
    }
    return;
}
void display() {
    struct node *temp;
    if (head->next == tail) {
            printf("Queue is empty\n");
            return;
    }

    temp = head->next;
    while (temp != tail) {
            printf("%-3d", temp->info);
            temp = temp->next;
    }
    printf("\n");
}

int main() {
    int info, ch;
    create();
    while (1) {
            printf("1. add at front\n2. add at rear\n");
            printf("3. delete at front\n4. delete at rear\n");
            printf("5. Display\n6. Exit\n");
            printf("Enter your choice:");
            scanf("%d", &ch);
            switch (ch) {
                        case 1:
                            printf("Enter the info to insert:");
                            scanf("%d", &info);
                            addAtFront(info);
                            break;

                        case 2:
                            printf("Enter ur info to insert:");
                            scanf("%d", &info);
                            addAtRear(info);
                            break;

                        case 3:
                            deleteAtFront();
                            break;
    
                        case 4:
                            deleteAtRear();
                            break;

                        case 5:
                            display();
                            break;

                        case 6:
                            exit(0);

                        default:
                            printf("Please enter valid option\n");
                            break;
            }
    }
    return 0;
}