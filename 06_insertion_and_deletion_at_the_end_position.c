#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *temp, *head = NULL;
int count=0;

void insert_E(int value)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL){
        head = new_node;
        count++;
        return;
    }
    else{
        temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        count++;
    }
}

void deletion_End(){
    struct node *ptr,*temp=head;
    if(head==NULL){
        printf("linked list is empty!\n");
     return;
    }
    if(temp->next==NULL){
        head=NULL;
        printf("%d has been deleted!\n",temp->data);
        free(temp);
       printf("Now linked list is empty!\n");
       count =count-1;
        return;
    }
    else{
        while(temp->next!=NULL){
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=NULL;
        printf("%d has been deleted!\n",temp->data);
            free(temp);
            count=count-1;
    }
}

void display(){
    temp = head;
    if (head == NULL){
        printf("\nLinked list is empty !");
        return;
    }
    while (temp != NULL){
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverse_d(){
    if (head == NULL){
        printf("\nLinked list is empty !");
        return;
    }
    int count = 0;
    temp = head;
    while (temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("NULL");
    for (int i = count; i >= 1; i--){
        temp = head;
        for (int j = 1; j < i; j++){
            temp = temp->next;
        }
        printf(" <-%d", temp->data);
    }
    printf("\n");
}

int main(){
    int v, num;
    char extra;
    printf("Enter:\n0 -> terminate program\n1 -> insertion at End position\n2 -> deletion from End position\n3 -> display \n4 -> reverse display\n");
    printf("\n");
    while (1){
        while (1){
            printf("\nEnter Your choice= ");
            if (scanf("%d%c", &num, &extra) == 2 && extra == '\n'){
                if (num >= 0 && num <= 4){
                    break;
                }
                else{
                    printf("Invalid range! Enter any number from 0 to 4.\n");
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
                insert_E(v);
                break;
        case 2: deletion_End();
                break;

        case 3: display();
                break;

        case 4: reverse_d();
                break;
        }
    }
    return 0;
}