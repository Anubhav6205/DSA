#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node *nextnodeaddress;

};

struct Node *start=NULL;
struct Node *end=NULL;

void inserinascendingorder(int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL)
    {
        printf("No elements found\n");
        return;
    }

    ptr->info=data;
    ptr->nextnodeaddress=NULL;

    if(start==NULL)
    {
        start=end=ptr;
    }
    else if(start->info>data)
    {
        ptr->nextnodeaddress=start;
        start=ptr;


    }
    else if(end->info<data)
    {
        end->nextnodeaddress=ptr;
        end=ptr;

    }
    else
    {
        struct Node *lol=start;
        struct Node *noob=start;

        while(lol!=NULL)
        {
            if(lol->info>data)
            {
                break;
            }
            lol=lol->nextnodeaddress;
        }

        
        while(noob->nextnodeaddress!=lol)
        {
            noob=noob->nextnodeaddress;

        }
        
        ptr->nextnodeaddress=lol;
        noob->nextnodeaddress=ptr;


    }
    
}

void printdata()
{
    struct Node *lol=start;

    if(lol==NULL)
    {
        printf("No nodes found\n");
        return;
    }
    printf("The linked list is \n");
    while(lol!=NULL)
    {
        printf("%d ",lol->info);
        lol=lol->nextnodeaddress;
    }
    printf("\n");
}

int main()
{
    inserinascendingorder(20);
    inserinascendingorder(30);
 
    printdata();
    inserinascendingorder(25);
    printdata();

}