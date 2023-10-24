#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*add;
};
struct node
*start=NULL,*temp,*New,*prev,*next;

void create();
void insert();
void Delete();
void display();
 
int main()
{
    int ch;
    do
    {
        printf("\n----------link list--------");
        printf("\npress 1 for create: ");
        printf("\npress 2 for insert: ");
        printf("\npress 3 for delete: ");
        printf("\npress 4 for display: ");
        printf("\npress 5 for exit: ");
        printf("\nenter a choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : create();break;
             case 2 : insert();break;
             case 3 : Delete();break;
             case 4 : display();break;
             case 5 : break;
             default: printf("\ninvalid number");
        }
    } while (ch!=5);
    return 0;
};
void create()
{   int n;
    char ch;
    if(start==NULL)
    {
         printf("\nenter a value: ");
        scanf("%d",&n);
        start = (struct node*)malloc(sizeof(struct node));
        start->data = n;
        start->add = NULL;
        temp = start;
        printf("\nto add more element in the list press'y'");
        scanf("%c",&ch);
        while(ch == 'y' || ch == 'Y')
        {
             printf("\nenter next value: ");
            scanf("$d",&n);
            New = (struct node*)malloc(sizeof(struct node));
            New -> data = n;
            New -> add = NULL;
            temp->add= New;
            temp = New;
            printf("\nto add more element in the list press'y'");
            scanf("%c",&ch);
        }
    }
    else
    {
       printf("\nlist is already created,,,,,,,,,");
    }
    
}
void insert()
{
    int n,position,count=0,i=1;
    if(start==NULL)
    {
    printf("\n list is not created ,,,,created first");
    }
    else
    {
        printf("\nenter a vallue: ");
        scanf("%d",&n);
        New = (struct node*)malloc(sizeof(struct node));
        New->data= n;
        New->add= NULL;
        printf("\nenter a position of new node: ");
        scanf("%d",&position);
        if(position==1)
        {
            New->add=start;
            start = New;
        }
        else
        {
            temp = start;
            while(temp!=NULL)
            {
                count++;
                temp = temp->add;
            }
            if(position>count+1)
            {
                printf("invalid no. it cant be more than %d",count+1);
            }
            else if (position==count+1)
            {
                temp=start;
                while(temp->add!= NULL)
                {
                    temp= temp->add;
                    temp->add=New;
                }
            }
            else
            {
                next = start;
                while(i<position)
                {
                    prev=next;
                    next = next->add;
                    i++;
                }
                prev->add = New;
                New->add= next;
            }
        }
    }
    
}
void Delete()
{
    int count=0,i=1,position;
    if(start == NULL)
    {
        printf("\n list is not created ,,,,created first");
    }
    else
    {
        printf("\nenter a position of deletion: ");
        scanf("%d",&position);
        if(position==1)
        {
            temp=start;
            start= start->add;
            printf("\ndeleted data = %d",temp->data);
            free(temp);
        }
        else
        {
            temp= start;
            while(temp!=NULL)
            {
                temp= temp->add;
                count++;
            }
            if(position>count)
            {
            printf("invalid no. it cant be more than %d",count);
            }
            else if(position == count)
            {
                temp = start;
                while(temp->add!=NULL)
                {
                    prev=temp;
                    temp=temp->add;
                }
                 printf("\ndeleted data = %d",temp->data);
                free(temp);
                prev->add = NULL;
            }
            else
            {
                next = start;
                while(i < position)
                {
                    prev = next;
                    next = next->add;
                    i++;
                }
                temp = next;
                next = next->add;
                printf("\ndeleted data = %d",temp->data);
                free(temp);
                prev->add = next;
            }
        }
    }
}
void display()
{
   if (start==NULL)
   {
    printf("\n list is not created ,,,,created first");
   }
   else
   {
    printf("\n");
    temp=start;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp = temp->add;
    }
    printf("\n");
   }
    
}

