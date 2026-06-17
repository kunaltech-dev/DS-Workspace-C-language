#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertion_P(int pos){
    if (pos <= 0){
        printf("Invalid Position!\n");
        return;
    }

    struct node *temp, *new;
    int value;

    new = (struct node *)malloc(sizeof(struct node));

    if (new == NULL){
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    new->data = value;
    new->next = NULL;
    new->prev = NULL;

    if (pos == 1){
        new->next = head;
        if (head != NULL){
            head->prev = new;
        }
        head = new;
        return;
    }
    temp = head;
    for (int i = 1; i < pos - 1; i++){
        if (temp == NULL){
            printf("Invalid Position!\n");
            free(new);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Invalid Position!\n");
        free(new);
        return;
    }
    new->next = temp->next;
    new->prev = temp;
    if (temp->next != NULL){
        temp->next->prev = new;
    }
    temp->next = new;
}

void deletion_P(int pos){
    if (pos <= 0){
        printf("Invalid pos!\n");
        return;
    }
    if (head == NULL){
        printf("Doubly Linked List is Empty!Please insertion first\n");
        return;
    }
    struct node *temp = head;
    if (pos == 1){
        if (temp->next == NULL){
            head = NULL;
            printf("%d has been deleted!\n", temp->data);
            free(temp);
            return;
        }
        else{
            head = temp->next;
            temp->next->prev = NULL;
            printf("%d has been deleted!\n", temp->data);
            free(temp);
            return;
        }
    }
    else{
        for (int i = 1; i < pos; i++){
            if (temp == NULL){
                printf("Invalid position!\n");
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL){
            printf("Invalid position!\n");
            return;
        }
        temp->prev->next = temp->next;
        if (temp->next != NULL){
            temp->next->prev = temp->prev;
        }
        printf("%d has been deleted \n", temp->data);
        free(temp);
    }
}

void display(){
    if (head == NULL){
        printf("Doubly Linked List is Empty! Please insert first\n");
        return;
    }
    else{
        struct node *temp;
        temp = head;
        printf("NULL<->");

        while (temp != NULL){
            printf("%d<->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void reverse_d(){
    struct node *temp;
    if (head == NULL){
        printf("Linked list is empty !\n");
        return;
    }
    temp = head;
    printf("Reverse Doubly Linked List:\n");
    printf("NULL");
    while (temp->next != NULL){
        temp = temp->next;
    }
    while (temp != NULL){
        printf("<->%d", temp->data);
        temp = temp->prev;
    }
    printf("<->NULL");

    printf("\n");
}

void freeList(){
    struct node *temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Memory freed successfully.\n");
}

int main(){
    int p, num;
    char extra;
    printf("Enter: \n0 -> terminate program \n1 -> insertion at specific position \n2 -> deletion from specific position \n3 -> display \n4 -> reverse display\n");
    while (1){
        while (1){
            printf("Enter Your choice: ");
            if (scanf("%d%c", &num, &extra) == 2 && extra == '\n'){
                if (num >= 0 && num <= 4){
                    break;
                }
                else{
                    printf("Invalid range !\n");
                }
            }
            else{
                printf("Invalid Input !\n");
                while (getchar() == '\n');
            }
        }
        switch (num){

        case 0:
            freeList();
            printf("Program Terminate Successfully !");
            return 0;

        case 1:
            printf("Enter position: ");
            scanf("%d", &p);
            insertion_P(p);
            break;

        case 2:
            printf("Enter Position: ");
            scanf("%d", &p);
            deletion_P(p);
            break;

        case 3:
            display();
            break;

        case 4:
            reverse_d();
            break;
        }
    }
    return 0;
}