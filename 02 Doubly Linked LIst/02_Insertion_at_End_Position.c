#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertion_E(int value){
    struct node *temp, *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    new->next = NULL;
    if (head == NULL){
        new->prev = NULL;
        head = new;
    }
    else{
        temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
}

void display(){
    if (head == NULL){
        printf("Doubly Linked List is Empty! Please insert first");
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
    int v, num;
    char extra;
    printf("Enter:\n0->Terminate program \n1->Insertion at End Position \n2->display \n");
    while (1){
        while (1){
            printf("\nEnter your choice: \n");
            if (scanf("%d%c", &num, &extra) == 2 && extra == '\n'){
                if (num >= 0 && num <= 2){
                    break;
                }
                else{
                    printf("Invalid range!");
                }
            }
            else{
                printf("Invalid input !");
                while (getchar() != '\n');
            }
        }
        switch (num){
        case 0:
            freeList();
            printf("Program terminate successfully\n");
            return 0;

        case 1:
            printf("Enter value: ");
            scanf("%d", &v);
            insertion_E(v);
            break;

        case 2:
            display();
            break;
        }
    }
    return 0;
}