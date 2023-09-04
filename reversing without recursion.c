#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;
void reverse(struct node** ref)
{
    struct node* prev = NULL;
    struct node* current =* ref;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
   * ref = prev;
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
   printf("The Linked List before being reversed:\n");
   display(head);
   reverse(&head);
   printf("After reversing the linked list:\n");
   display(head);
}
   
