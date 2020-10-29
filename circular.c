#include<stdio.h>   
#include<stdlib.h>
#define max 4
int array[max];
int rear=-1;
int front=-1;
void insert()
{
    int x;
    printf("Enter the info\n");
    scanf("%d",&x);
    if(rear==-1)
    {
        rear=0;
        front=0;
    }
    else if(rear==max-1)
    {
        rear=0;
    }
    else
    {
        rear++;
    }
    array[rear]=x;
}
void delete()
{
    int a=array[front];
    if(rear==front)
    {
        front=-1,rear=-1;
    }
    else if (front==max-1)
    {
        front=0;
    }
    else
    {
        front++;
    }
    printf("The deleted info is: %d",a);
}
void display()
{
    if(front>rear)
    {
        for(int i=front;i<max;i++)
        {
            printf("%d ",array[i]);
        }
        for(int j=0;j<rear;j++)
        {
            printf("%d ",array[j]);
        }
    }
    else
    {
        for(int i=front;i<=rear;i++)
        printf("%d ",array[i]);
    }
    
}
int f=-1,r=-1;  
int q[10];  
void main ()  
{
    
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