#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertion_F(int value){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    new->prev = NULL;
    new->next = head;
    if (head != NULL){
        head->prev = new;
    }
    head = new;
}

void count_Node(){
    struct node *temp=head;
   int count=0;
   while(temp != NULL){
    temp=temp->next;
    count++;
   }
   printf("Total nodes is %d\n",count);    
}

void display(){
    struct node *temp = head;
    if(head == NULL){
        printf("Linked List is Empty!\n");
            return;
    }
    printf("Doubly Linked List is :\n");
    printf("NULL<->");
    while (temp != NULL){
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
    printf("Enter: \n0 -> terminate program\n1 -> insertion at First \n2 -> count nodes \n3 -> display \n");
    while (1){
        while (1){
            printf("\nEnter Your choice= ");
            if (scanf("%d%c", &num, &extra) == 2 && extra == '\n'){
                if (num >= 0 && num <= 3){
                    break;
                }
                else{
                    printf("Invalid range! Enter any number from 0 to 3.\n");
                }
            }
            else{
                printf("Invalid input! Enter only an integer.\n");
                while (getchar() != '\n');
            }
        }
        switch (num){

        case 0:
            freeList();
            printf("Program terminate Successfully ");
            return 0;

        case 1:
            printf("Enter value=");
            scanf("%d", &v);
            insertion_F(v);
            break;

        case 2:
            count_Node();
            break;
        
        case 3:
            display();
            break;
        }
    }
    return 0;
}