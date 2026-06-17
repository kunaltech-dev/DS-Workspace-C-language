#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertion_E(int value){
    struct node *temp, *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL){
        new_node->prev = NULL;
        head = new_node;
    }
    else{
        temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void deletion_E(){
    struct node *temp = head;
    if (head == NULL){
        printf("Doubly Linked List is empty!\n");
        return;
    }
    else{
        if (temp->next == NULL){
            head = NULL;
            printf("%d has been deleted!\n", temp->data);
            free(temp);
        }
        else{
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->prev->next = NULL;
            printf("%d has been deleted!\n", temp->data);
            free(temp);
        }
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
        printf("Doubly Linked list is empty ! Please insert first\n");
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
    int v, num;
    char extra;
    printf("Enter:\n0->Terminate program \n1->Insertion at End Position \n2 -> deletion from end position \n3->display \n4 -> reverse display\n");
    while (1){
        while (1){
            printf("\nEnter your choice: ");
            if (scanf("%d%c", &num, &extra) == 2 && extra == '\n'){
                if (num >= 0 && num <= 4){
                    break;
                }
                else{
                    printf("Invalid range!\n");
                }
            }
            else{
                printf("Invalid input !\n");
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
            deletion_E();
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