#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
int count = 0;

void insert_P(int pos){
    struct node *new_node, *temp = head;
    int value;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (pos <= 0){
        printf("Invalid position !\n");
        free(new_node);
        return;
    }
    else if (pos == 1){
        printf("Enter value=");
        scanf("%d", &value);
        new_node->data = value;
        new_node->next = head;
        head = new_node;
        count++;
    }
    else{
        for (int i = 1; i < pos - 1; i++){
            if (temp == NULL){
                printf("Invalid position !\n");
                free(new_node);
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL){
            printf("Invalid position !\n");
            free(new_node);
            return;
        }
        printf("Enter value=");
        scanf("%d", &value);
        new_node->data = value;
        new_node->next = temp->next;
        temp->next = new_node;
        count++;
    }
}

void delete_p(int pos){
    struct node *ptr, *loc;
    if(pos <= 0){
        printf("Invalid position!");
            return;
    }
    if (head == NULL){
        printf("Linked list is Empty!\n");
        return;
    }
    if (pos == 1){
        ptr = head;
        head = head->next;
        printf("deleted element is %d\n", ptr->data);
        free(ptr);
        count--;
        return;
    }
    ptr = head;
    for (int i = 1; i < pos; i++){
        loc = ptr;
        ptr = ptr->next;
        if (ptr == NULL){
            printf("Invalid position !\n");
            return;
        }
    }
    loc->next = ptr->next;
    printf("Deleted element is %d\n", ptr->data);
    free(ptr);
    count--;
}

void display(){
    struct node *temp = head;
    if (head == NULL){
        printf("\nLinked list is empty !\n");
        return;
    }
    while (temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse_d(){
    struct node *temp;
    if (head == NULL){
        printf("\nLinked list is empty !");
        return;
    }
    temp = head;
    printf("NULL");
    for (int i = count; i >= 1; i--){
        temp = head;
        for (int j = 1; j < i; j++){
            temp = temp->next;
        }
        printf("<-%d", temp->data);
    }
    printf("\n");
}

int main(){
    int P, p1, num;
    char extra;
    printf("Enter: \n0 -> terminate program\n1 -> insertion at specific position \n2 -> delete from specific position \n3 -> display \n4 -> reverse display\n");
    while (1){
        while (1){
            printf("\nEnter Your choice= ");
            if (scanf("%d%c", &num, &extra) == 2 && extra == '\n'){
                if (num >= 0 && num <= 4){
                    break;
                }
                else{
                    printf("Invalid range! Enter choice number from 0 to 4.\n");
                }
            }
            else{
                printf("Invalid input! Enter only an integer.\n");
                while (getchar() != '\n')
                    ;
            }
        }
        switch (num){

        case 0:
            printf("Program terminate Successfully ");
            return 0;

        case 1:
            printf("Enter position=");
            scanf("%d", &P);
            insert_P(P);
            break;

        case 2:
            printf("Enter position: ");
            scanf("%d", &p1);
            delete_p(p1);
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