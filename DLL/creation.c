#include <stdio.h>
#include <stdlib.h>

int choice = 1;

int main()
{
    struct Node
    {
        struct Node *prev;
        struct Node *next;
        int data;
    } *head = NULL, *end = NULL, *newnode, *temp;

    while (choice)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        if (newnode == NULL)
        {
            printf("The node is full\n");
        }
        else
        {
            printf("Enter the value of new node\n");
            scanf("%d", &newnode->data);
            newnode->next = NULL;
            newnode->prev = NULL;

            if (head == NULL)
            {
                head = end = newnode;
            }
            else
            {
                end->next = newnode;
                newnode->prev = end;
                end = newnode;
            }
        }
        printf("Press 1 to add new node or 0 to exit\n");
        scanf("%d", &choice);
    }

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

   
    return 0;
}
