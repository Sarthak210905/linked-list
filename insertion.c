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
  struct node *head = NULL, *new;
  
  new = (struct node*)malloc(sizeof(struct node));
  printf("enter the value of new node\n");
  scanf("%d",&new->data);
  if(head == NULL)
  {
    head=new;
    new->next=NULL;
  }
  else{
    new->next=head;
    head=new;
  }
    printf("%d\n",head->data);

    return 0;
}