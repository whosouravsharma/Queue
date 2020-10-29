#include<stdio.h>   
#include<stdlib.h>  
typedef struct node
{  
    int info;   
    struct node *link;  
}node;  
struct node *f;  
struct node *r;
void insert()
{
    printf("Enter the info\n");
    if(!f->info)
    {
        scanf("%d",&f->info);
        f->link=NULL;
        r=f;
    }
    else
    {
        if(f==NULL)
        {
            printf("The queue is already empty\n");
            return;
        }
        node *new=(node*)malloc(sizeof(node));
        scanf("%d",&new->info);
        r->link=new;
        new->link=NULL;
        r=new;
    }
    
}
void delete()
{
    node*temp=f;
    f=f->link;
    free(temp);
}
void display()
{
    node*temp=f;
    if(!temp->info)
    {
        printf("Empty list\n");
        return;
    }
    do
    {
        printf("%d ",temp->info);
        temp=temp->link;
    } while (temp!=NULL);
}
void main ()
{  
    f=(node*)malloc(sizeof(node));  
    int ch;   
    while(ch!=4)   
    {     
        printf("\n*****QUEUE*****\n");
        printf("Enter your choice: \n");
        printf("1. Display Queues\n");
        printf("2. Add a Queue\n");
        printf("3. Delete a Queue\n");  
        printf("4. Exit\n");  
        printf("Enter your choice: ");  
        scanf("%d",&ch);  
        switch(ch)  
        {  
            case 1:  
            display();  
            break;  
            case 2:  
            insert();  
            break;  
            case 3:  
            delete();
            break;  
            case 4:  
            exit(0);  
            break;  
            default:   
            printf("Enter valid choice.\n");  
        }  
    }  
}