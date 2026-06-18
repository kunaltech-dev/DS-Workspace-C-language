#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insertion_F(int value){
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL){
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = head;
    if (head != NULL){
        head->prev = new_node;
    }
    head = new_node;
}

void insertion_E(int value){
    struct node *temp, *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL){
        printf("Memory allocation failed!\n");
        return;
    }
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

void insertion_P(int pos){
    if (pos <= 0){
        printf("Invalid Position!\n");
        return;
    }

    struct node *temp, *new_node;
    int value;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL){
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (pos == 1){
        new_node->next = head;
        if (head != NULL){
            head->prev = new_node;
        }
        head = new_node;
        return;
    }
    temp = head;
    for (int i = 1; i < pos - 1; i++){
        if (temp == NULL){
            printf("Invalid Position!\n");
            free(new_node);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Invalid Position!\n");
        free(new_node);
        return;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL){
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

void deletion_F(){
    struct node *temp = head;
    if (head == NULL){
        printf("Linked List is Empty! Please Insertion first\n");
        return;
    }
    else{
        if (temp->next == NULL){
            head = temp->next;
            printf("%d has been deleted!\n", temp->data);
            free(temp);
            return;
        }
        else{
            temp->next->prev = NULL;
            head = temp->next;
            printf("%d has been deleted!\n", temp->data);
            free(temp);
        }
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

void count_Node(){
    struct node *temp = head;
    int count = 0;
    while (temp != NULL){
        temp = temp->next;
        count++;
    }
    printf("Total nodes is %d\n", count);
}

void display(){
    struct node *temp = head;
    if (head == NULL){
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
    printf("<->NULL\n");
}

void search_N(){
struct node *temp=head;
int value;
printf("Enter the number you want to find: ");
scanf("%d",&value);
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
    int v, p, num;
    char extra;
    printf("Enter: \n0 -> Terminate Program \n1 -> Insertion at First Position");
    printf("\n2 -> Insertion at End Position \n3 -> Insertion at Specific Position");
    printf("\n4 -> Deletion From First Position \n5 -> Deletion From End Position");
    printf("\n6 -> Deletion From Specific Position \n7 -> Count Total node");
    printf("\n8 -> Display \n9 -> Reverse Display \n10 -> Search Value");

    while (1){        
        while (1){
            printf("\nEnter Your choice= ");
            if (scanf("%d%c", &num, &extra) == 2 && extra == '\n'){
                if (num >= 0 && num <= 10){
                    break;
                }
                else{
                    printf("Invalid range! Enter any number from 0 to 10.\n");
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
            printf("Enter value: ");
            scanf("%d", &v);
            insertion_E(v);
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d", &p);
            insertion_P(p);
            break;

        case 4:
            deletion_F();
            break;

        case 5:
            deletion_E();
            break;

        case 6:
            printf("Enter Position: ");
            scanf("%d", &p);
            deletion_P(p);
            break;

        case 7:
            count_Node();
            break;

        case 8:
            display();
            break;

        case 9:
            reverse_d();
            break;

        case 10:
            search_N();
            break;
        }
    }
    return 0;
}