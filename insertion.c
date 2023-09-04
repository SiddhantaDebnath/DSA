#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;
void insertAtFront()
{
    int d;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &d);
    temp->data = d;
    temp->next = head;
    head = temp;
}
void insertAtEnd()
{
    int d;
    struct node *temp, *start;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &d);
    temp->next = NULL;
    temp->data = d;
    start = head;
    while (start->next != NULL) {
        start = start->next;
    }
    start->next = temp;
}
void insertAtPosition()
{
    struct node *temp, *newnode;
    int pos, d, i = 1;
    newnode = malloc(sizeof(struct node));
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &d);
    temp = head;
    newnode->data = d;
    newnode->next = 0;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void display(struct node *head){
   struct node *temp;
   temp=head;
   while(temp!=NULL){
      printf("%d",temp->data);
      temp=temp->next;
      printf("\n");
   }
}
int main()
{
    struct node *temp;
	int choice;
    int n=1;
   char option,enter;
   head=(struct node *)malloc(sizeof(struct node));
   temp=head;
   do{
      printf("\nEnter No. %d data for the linked list: ",n);
      scanf("%d",&temp->data);
      printf("\nDo you want continue Y(es) | N(o) : ");
      scanf("%c",&enter);
      scanf("%c",&option);
      if (option!='N'){
      	n++;
         temp->next=(struct node *)malloc(sizeof(struct node));
         temp=temp->next;
      } else {
         temp->next=NULL;
      }
   }while(option!='N');
    while (1) {
        printf("\t1  For insertion at"
               " starting\n");
        printf("\t2  For insertion at"
               " end\n");
        printf("\t3  For insertion at "
               "any position\n");
        printf("\t4 To display\n");
        printf("\t5 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
        case 1:
            insertAtFront();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
        	display(head);
        	break;
        case 5:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}
