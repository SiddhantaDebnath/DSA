#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;
void deleteFirst()
{
    struct node* temp;
    if (head == NULL)
        printf("\nList is empty\n");
    else {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void deleteEnd()
{
    struct node *temp, *prev;
    if (head == NULL)
        printf("\nList is Empty\n");
    else {
        temp = head;
        while (temp->next != 0) {
            prev = temp;
            temp = temp->next;
        }
        free(temp);
        prev->next = 0;
    }
}
void deletePosition()
{
    struct node *temp, *posi;
    int i = 1, pos;
    if (head == NULL)
        printf("\nList is empty\n");
    else {
        printf("\nEnter index : ");
        scanf("%d", &pos);
        posi = malloc(sizeof(struct node));
        temp = head;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        posi = temp->next;
        temp->next = posi->next;
        free(posi);
    }
}
void display(struct node *head){
   struct node *temp;
   if(head==NULL)
   printf("\nList is empty\n");
   else{
   	  temp=head;
      while(temp!=NULL){
      	printf("%d",temp->data);
      	temp=temp->next;
     	 printf("\n");
  	  }
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
      } 
	  else {
         temp->next=NULL;
      }
   }
   while(option!='N');
    while (1) {
        printf("\t1  For deletion in the beginning\n");
        printf("\t2  For deletion in the end\n");
        printf("\t3  For deletion at any position\n");
        printf("\t4 To display\n");
        printf("\t5 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
        case 1:
            deleteFirst();
            break;
        case 2:
            deleteEnd();
            break;
        case 3:
            deletePosition();
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
