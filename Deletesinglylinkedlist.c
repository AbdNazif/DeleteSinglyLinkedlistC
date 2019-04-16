#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void printlist(struct node *head)
{
    struct node *ptr = head;
    while(ptr){
        printf("%d->",ptr -> data);
    }
    printf("NULL");
}

void push(struct node **head,int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = *head;
    *head = newnode;
}

void deleteB(struct node **head)
{
    struct node *temp = *head;
    head = head->next;
    free(temp);
    printf("\nThe element is successfully deleted");
}

void deleteE(struct node **head)
{
    struct node *todelete, *secondlastnode;
    if(*head == NULL)
    {
        printf("The list is already Empty");
    }
    else
    {
        todelete = *head;
        secondlastnode = *head;
        while(todelete -> next!= NULL)
        {
            secondlastnode =todelete;
            todelete = todelete -> next;
        }
        if (todelete == *head) {
            *head = NULL;
        }
        else
            {
            secondlastnode -> next = NULL;
        }

        free(todelete);
        printf("The element is deleted successfully");

    }
    
}

int main()
{
    int opt,d;
    struct node *head = NULL;
    do
    {
        printf("\n\nCurrent List\n\n1.Insert\n2.Delete Element from Beginning\n3.Delete element fromt he end\n4.Quit\nChoose your Option:");
        scanf("%d",&opt);
        switch (opt)
        {
            case 1:
                printf("Enter the Element:");
                scanf("%d",&d);
                push(&head,d);
                printf("Element Inserted");
                break;

            case 2:
                deleteB(&head);
                break;
            case 3:
                deleteE(&head);
                break;
            case 4:
                break;

            default:
                printf("Invalid Input");
                break;
        }
    } 
    while (opt<4);
    
    return 0;


}