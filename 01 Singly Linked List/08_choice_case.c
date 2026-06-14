#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *temp, *head = NULL;
int count = 0;
void insert_F(int value){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    new->next = head;
    head = new;
    count++;
}

void insert_E(int value){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    new->next = NULL;
    if (head == NULL){
        head = new;
        count++;
        return;
    }
    else{
        temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new;
        count++;
    }
}

void insert_P(int pos){
    struct node *new;
    int value;
    temp = head;

    new = (struct node *)malloc(sizeof(struct node));

    if (pos <= 0){
        printf("Invalid position !\n");
        free(new);
        return;
    }
    else if (pos == 1){
        printf("Enter value=");
        scanf("%d", &value);
        new->data = value;
        new->next = head;
        head = new;
        count++;
    }
    else{
        for (int i = 1; i < pos - 1; i++){
            if (temp == NULL){
                printf("Invalid position !\n");
                free(new);
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL){
            printf("Invalid position !\n");
            free(new);
            return;
        }
        printf("Enter value=");
        scanf("%d", &value);
        new->data = value;
        new->next = temp->next;
        temp->next = new;
        count++;
    }
}

void deletion_F(){
    temp = head;
    if (head == NULL){
        printf("Linked is empty ! \nPlease insert some data before deleting !");
    }
    else{
        head = temp->next;
        printf("%d has been deleted!", temp->data);
        free(temp);
        count--;
    }
}

void deletion_E(){
    struct node *ptr;
    temp = head;
    if (head == NULL){
        printf("linked list is empty!\n");
        return;
    }
    if (temp->next == NULL){
        head = NULL;
        printf("%d has been deleted!\n", temp->data);
        free(temp);
        printf("Now linked list is empty!\n");
        count--;
        return;
    }
    else{
        while (temp->next != NULL){
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = NULL;
        printf("%d has been deleted!\n", temp->data);
        free(temp);
        count--;
    }
}

void deletion_p(int pos){
    struct node *ptr, *loc;
    if (pos <= 0){
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
        printf("%d has been deleted!\n", ptr->data);
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
    temp = head;
    if (head == NULL){
        printf("\nLinked list is empty !");
        return;
    }
    while (temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse_d(){
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
    int v, p, num;
    char extra;
    printf("Enter: \n0 -> terminate program\n1 -> insertion at first \n2 -> insertion at End");
    printf("\n3 -> insertion at specific position \n4 -> delete from first \n5 -> delete from End");
    printf("\n6 -> delete from specific position \n7 -> display \n8 -> Reverse display");

    while (1){
        while (1){
            printf("\nEnter Your choice= ");
            if (scanf("%d%c", &num, &extra) == 2 && extra == '\n'){
                if (num >= 0 && num <= 8){
                    break;
                }
                else{
                    printf("Invalid range! Enter choice number from 0 to 8.\n");
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
            printf("Enter value=");
            scanf("%d", &v);
            insert_F(v);
            break;

        case 2:
            printf("Enter value=");
            scanf("%d", &v);
            insert_E(v);
            break;

        case 3:
            printf("Enter position=");
            scanf("%d", &p);
            insert_P(p);
            break;

        case 4:
            deletion_F();
            break;

        case 5:
            deletion_E();
            break;

        case 6:
            printf("Enter position: ");
            scanf("%d", &p);
            deletion_p(p);
            break;

        case 7:
            display();
            break;

        case 8:
            reverse_d();
            break;
        }
    }
    return 0;
}