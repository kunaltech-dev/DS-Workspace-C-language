#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_P(int pos){
struct node *new_node,*temp=head;
int value;

new_node = (struct node *)malloc(sizeof(struct node));

if(pos <= 0){
    printf("Invalid position !\n");
    free(new_node);
    return;
}
else if(pos == 1){
    printf("Enter value=");
    scanf("%d",&value);
    new_node->data=value;
    new_node->next=head;
    head=new_node;
}
else{
    for(int i=1;i<pos-1;i++){
        if(temp == NULL){
            printf("Invalid position !\n");
            free(new_node);
            return ;
        }
        temp=temp->next;
    }
    if(temp == NULL){
    printf("Invalid position !\n");
    free(new_node);
    return;
}
    printf("Enter value=");
    scanf("%d",&value);
    new_node->data = value;
    new_node->next=temp->next;
    temp->next=new_node;
}
}

void display(){
    struct node *temp=head;
    temp = head;
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
        printf("<-%d", temp->data);
    }
    printf("\n");
}

int main(){
    int P, num;
    char extra;
    printf("Enter: \n0 -> terminate program\n1 -> insertion \n2 -> display \n3 -> reverse display\n");
    while (1){
        while (1){
            printf("\nEnter Your choice= ");
            if (scanf("%d%c", &num, &extra) == 2 && extra == '\n'){
                if (num >= 0 && num <= 3){
                    break;
                }
                else{
                    printf("Invalid range! Enter number from 0 to 3.\n");
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

        case 1: printf("Enter position=");
                scanf("%d", &P);
                insert_P(P);
                break;

        case 2: display();
                break;

        case 3: reverse_d();
                break;
        }
    }
    return 0;
}