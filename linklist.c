#include <stdio.h>
#include<stdlib.h>

int choice = 1;
int count = 0;

int main()
{
  struct node
  {
    int data;
    struct node *next;
  };
  struct node *head = NULL, *new,*temp;

  while (choice)
  {
    
 
  new = (struct node*)malloc(sizeof(struct node));

    // printf("___________________________________\n");
  if (new == NULL)
  {
    printf("the node is full\n");

  }

  else
  {
    printf("the value of node ");
    scanf("%d", &new->data);

    new->next= NULL;
  }
  // head = new;
  //count++;

  if (head == NULL)
  {
   head = temp = new;
  }
  else
  {
    temp->next=new;
    temp = temp->next;
  }
  printf("press 1 for add new node or 0 to exsit\n",choice);
  scanf("%d",&choice);
  
  }
  temp = head;
  while(temp != NULL)
  {
  
  printf("%d\n",temp->data);
  temp = temp->next;
  }

 
 
   
}