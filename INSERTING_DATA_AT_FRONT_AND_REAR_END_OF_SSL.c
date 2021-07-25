#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int info;
    struct Node *nextnodeaddress;

};

struct Node *start=NULL;
struct Node *end=NULL;

void insertdataatfront(int Data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));

    if(ptr==NULL)
    {
        printf("Memory couldn't be allocated");
        return;
    }
    ptr ->info=Data;
    ptr ->nextnodeaddress=NULL;

    if(start==NULL) //linking data
    {
        start=end=ptr;
    }
    else{
        ptr -> nextnodeaddress=start;
        start=ptr;
    }
}


void printdata()
{
    struct Node *ptr = start;

    if(ptr ==NULL)
    {
        printf("The linked list is empty");
    }

    printf("The linked list is \n");
    while(ptr !=NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->nextnodeaddress;
    }
    printf("\n");


}
void insertdataatrearend(int Data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL)
    {
        printf("Memory wasn't allocated");
    }
    ptr->info=Data;
    ptr->nextnodeaddress=NULL;

    if(start==NULL)
    {
        end=start=ptr;
    }
    else
    {
        end->nextnodeaddress=ptr;
        end=ptr;
       
    }
}
int main()
{
    insertdataatfront(20);
    printdata();
    insertdataatfront(60);
    printdata();
    insertdataatrearend(30);
    printdata();
    insertdataatrearend(120);
    printdata();
}