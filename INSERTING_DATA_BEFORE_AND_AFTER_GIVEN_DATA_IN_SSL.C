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
struct Node *searchnode(int Data)
{
    struct Node *ptr=start;
    if(start==NULL)
    {
        printf("No nodes found");
        return NULL;
    }
    while(ptr!=NULL)
    {
        if(ptr->info==Data)
        {
            return ptr;
        }
        ptr=ptr->nextnodeaddress;
    }
    printf("\n");

}
void insertdataaftergivendata(int Data,int key)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *seachednode=searchnode(key);
    if(searchnode==NULL)
    {
        printf("The key doesnt exist");
        return;
    }
    if(ptr==NULL)
    {
        printf("Memory can't be allocated");
    }
    ptr->info=Data;
    ptr->nextnodeaddress=NULL;

    if(seachednode==end)
    {
        end->nextnodeaddress=ptr;
        end=ptr;

    }
    else
    {
        ptr->nextnodeaddress=seachednode->nextnodeaddress;
        seachednode->nextnodeaddress=ptr;
        
    }
}

void insertdatabeforegivendata(int Data,int key)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *searchednode=searchnode(key);
    if(searchednode==NULL)
    {
        printf("Key not found");
        return;
    }
    if(ptr==NULL)
    {
        printf("memory cant be allocated");
        return;
    }
    ptr->info=Data;
    ptr->nextnodeaddress=NULL;

    if(searchednode==start)
    {
        ptr->nextnodeaddress=start;
        start=ptr;
    }
    else
    {
        struct Node *lol=start;
        while(lol->nextnodeaddress!=searchednode)
        {
            lol=lol->nextnodeaddress;
        }
        lol->nextnodeaddress=ptr;
        ptr->nextnodeaddress=searchednode;
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
    insertdataaftergivendata(69,30);
    printdata();
    insertdatabeforegivendata(56,30);
    printdata();
}