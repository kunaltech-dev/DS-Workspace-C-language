#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *temp, *head = NULL;

void insert_F(int value){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    new->next = head;
    head = new;
}

void count_node(){
    int count=0;
   temp=head;
   if(head == NULL){
    printf("Linked List is Empty! Please insert data first\n");
        return;
   }
   else{
   while(temp != NULL){
    count++;
    temp=temp->next;
   }
   printf("Total number of node is %d\n",count);
}
}

void search_N(){
int value;
printf("Enter the number you want to find: ");
scanf("%d",&value);
temp=head;
if(head == NULL){
    printf("Linked List is Empty! Please insert data first.\n");
        return;
}
else{
while(temp != NULL){
    if(temp->data == value){
        printf("%d is present in Linked List\n",value);
            return;
    }
    temp=temp->next;
}
printf("%d is not present in Linked List\n",value);
}
}

int main(){
    int v,num;
    char extra;
printf("Enter: \n0 -> Terminate program \n1 -> insertion at first position \n2 -> count node \n3 -> search value");
    

    while (1){
        while (1){
            printf("\nEnter Your choice= ");
            if (scanf("%d%c", &num, &extra) == 2 && extra == '\n'){
                if (num >= 0 && num <= 3){
                    break;
                }
                else{
                    printf("Invalid range! Enter choice number from 0 to 3.\n");
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
            count_node();
            break;
        
        case 3:
             search_N();
             break;
        }
    }
    return 0;
}