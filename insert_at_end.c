#include <stdio.h>
#include <stdlib.h>
int choice=1;

int main()
{
    struct node
  {
    int data;
    struct node *next;
  };
  struct node *head = NULL, *new,*temp;
  
  new = (struct node*)malloc(sizeof(struct node));
  printf("enter the value of new node\n");
  scanf("%d",&new->data);
  if(head == NULL)
  {
    head=new;
    new->next=NULL;
  }
  else{
   temp=head;
   while(temp!=NULL)
   {
     temp = temp->next;
   }
   temp->next=new;
   new->next=NULL;

  }
    printf("%d\n",new->data);

    return 0;
}