#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;

void insertion_first(int value){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    new->next = start;
    start = new;
}

void insertion_end(int value){
    struct node *new2, *temp;
    new2 = (struct node *)malloc(sizeof(struct node));
    new2->data = value;
    new2->next = NULL;
    if (start == NULL){
        start = new2;
    }
    else{
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new2;
    }
}

void display(){
    struct node *temp=start;
    temp = start;
    if (start == NULL){
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
    if (start == NULL){
        printf("\nLinked list is empty !");
        return;
    }
    int count = 0;
    temp = start;
    while (temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("NULL");
    for (int i = count; i >= 1; i--){
        temp = start;
        for (int j = 1; j < i; j++){
            temp = temp->next;
        }
        printf("<-%d", temp->data);
    }
    printf("\n");
}

int main(){
    int v, num;
    char extra;
    printf("Enter: \n0 -> terminate program\n1--> insertion from the first\n2 -> insertion from End\n3--> display \n4 -> reverse display\n");
    while (1){
        while (1){
            printf("\nEnter Your choice= ");
            if (scanf("%d%c", &num, &extra) == 2 && extra == '\n'){
                if (num >= 0 && num <= 4){
                    break;
                }
                else{
                    printf("Invalid range! Enter Choice number from 0 to 4.\n");
                }
            }
            else{
                printf("Invalid input! Enter only an integer.\n");
                while (getchar() != '\n')
                    ;
            }
        }
        switch (num){

        case 0: printf("Program terminate Successfully ");
                return 0;

        case 1: printf("Enter value=");
                scanf("%d", &v);
                insertion_first(v);
                break;
        
        case 2: printf("Enter value=");
                scanf("%d",&v);
                insertion_end(v);
                break;

        case 3: display();
                break;

        case 4: reverse_d();
                break;
        }
    }
    return 0;
}