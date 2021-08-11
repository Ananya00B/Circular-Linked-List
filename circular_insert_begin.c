#include<stdio.h>
#include<stdlib.h>

void CLLinsertAtTheBeginning();
void display();

struct node
{
    int data;
    struct node *next;
};
struct node *tail;

int main()
{
    int opt = 1;
    tail = (struct node*) malloc(sizeof(struct node));
    tail = 0;
    printf("Circular Linked List : insertion at the beginning,\n\n");
    do{
        CLLinsertAtTheBeginning();
        printf("\nDo you want to insert an element at the beginning?\n");
        printf("Choose : 1 -> YES, any other no. -> NO : ");
        scanf("%d", &opt);
    }while(opt == 1);

    return 0;
}

void CLLinsertAtTheBeginning()
{
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode == 0)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        if(tail == 0)
        {
            printf("Enter the first element to insert : ");
            scanf("%d", &newNode->data);
            tail = newNode;
            tail->next = newNode;
            newNode->next = tail->next;
        }
        else
        {
            printf("Enter the element to insert : ");
            scanf("%d", &newNode->data);
            newNode->next = tail->next;
            tail->next = newNode;
        }
        display();
    }
}

void display()
{
    if(tail == 0)
    {
        printf("\nList is empty.\n");
        return;
    }

    printf ("\nCircular Linked List: \n");
    struct node *temp;
    temp = tail->next;
    while (temp->next != tail->next)
    {
        printf ("%d", temp->data);
        temp = temp->next;
        printf(" -> ");
    }
    printf("%d ->\n", temp->data);
}