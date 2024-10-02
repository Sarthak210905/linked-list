#include <stdio.h>
#include <stdlib.h>

int choice = 1;
int choices = 1;
int option;
int count = 0;
int position;

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
            printf("----------------------------------------\n");
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
            count++;
        }
        printf("Press \n 1 to add new node \n 0 to stop \n");
        scanf("%d", &choice);
        printf("----------------------------------------\n");
    }
    while (choices)
    {

        printf("Press \n 1 for print \n 2 for insert at beginning \n 3 for insert at end \n 4 for insert at any position \n 5 for delete at beginning \n 6 for delete at end \n 7 for delete at any position \n 8 for reverse  \n 9 for exit\n");
        scanf("%d", &option);
        printf("----------------------------------------\n");

        if (option == 1)
        {
            temp = head;
            printf("total elements are  %d\n", count);
            while (temp != NULL)
            {
                printf("%d \n", temp->data);
                temp = temp->next;
            }
            printf("----------------------------------------\n");
        }
        else if (option == 2)
        {

            newnode = (struct Node *)malloc(sizeof(struct Node));
            if (newnode == NULL)
            {
                printf("The memory is full\n");
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
                    newnode->next = head;
                    head->prev = newnode;
                    head = newnode;
                }
                count++;
            }
        }
        else if (option == 3)
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
                printf("----------------------------------------\n");
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
                count++;
            }
        }
        else if (option == 4)
        {
            newnode = (struct Node *)malloc(sizeof(struct Node));
            if (newnode == NULL)
            {
                printf("The node is full\n");
            }
            else
            {
                printf("Enter the positin of new node\n");
                scanf("%d", &position);
                printf("Enter the value of new node\n");
                scanf("%d", &newnode->data);
                printf("----------------------------------------\n");
                newnode->next = NULL;
                newnode->prev = NULL;
                if (0 < position && count >= position)
                {
                    temp = head;
                    int i;
                    while (i <= position - 1)
                    {
                        temp = temp->next;
                        i++;
                    }

                    newnode->next = temp->next;
                    temp->next->prev = newnode;
                    temp->next = newnode;
                    newnode->prev = temp;
                    count++;
                }
                else
                {
                    printf("Invalid position\n");
                }
            }
        }
        else if (option == 5)
        {
            temp = head;
            head = head->next;
            head->prev = NULL;
            count--;
            free(temp);
        }
        else if (option == 6)
        {
            temp = end;
            end = end->prev;
            end->next = NULL;
            count--;
            free(temp);
        }
        else if (option == 7)
        {
            printf("Enter the position to delete\n");
            scanf("%d", &position);

            if (0 < position && count >= position)
            {
                temp = head;
                int i = 1;

                while (i < position)
                {
                    temp = temp->next;
                    i++;
                }

                
                if (temp == head)
                {
                    head = temp->next;
                    if (head != NULL) 
                        head->prev = NULL;
                }
               
                else if (temp->next == NULL)
                {
                    temp->prev->next = NULL;
                }
               
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }

                free(temp);
                count--;
            }
            else
            {
                printf("Invalid position\n");
            }
        }

        else if (option == 8)
        {
            temp = head;
            while (temp != NULL)
            {
                newnode = temp->next;
                temp->next = temp->prev;
                temp->prev = newnode;
                temp = newnode;
            }
            newnode = head;
            head = end;
            end = newnode;
        }

        else
        {
            choices = 0;
        }
    }
    return 0;
}