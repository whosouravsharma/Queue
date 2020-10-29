#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 4


int f=-1;
int r=-1;

// create a queue
int q[max];
// display
void display()
{
    if(r==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The data in queue are: \n");
    for(int i=f;i<max;i++)
    {
        printf("%d ",q[i]);
    }
}

// push
void push()
{
    int data;
    printf("Enter the data to be puched\n");
    scanf("%d",&data);
    if(r==max-1)
    printf("OVERFLOW\n");
    if(r==-1&&f==-1)
    {
        r=0;
        f=0;
    }
    else
    {
        r=r+1;
    }
    q[r]=data;
}
// pop
void pop()
{
    if(f==-1&&r==-1)
    printf("UNDERFLOW\n");
    if(f==r)
    {
        f=-1;r=-1;
    }
    else
    {
        f=f+1;
    }
}
int main()
{
    int ch1,ch3;
    char ch2;
    int flag=1;
    while(flag==1)
    {
        printf("\n*****QUEUE*****\n");
        printf("Enter your choice: \n");
        printf("1. Display Queues\n");
        printf("2. Add a Queue\n");
        printf("3. Delete a Queue\n");
        scanf("%d",&ch1);

        switch(ch1)
        {
            case 1:display();  
            break;
            case 2:push();
            break;
            case 3:pop();
            break;
        }
        
        printf("Do you wish to continue?(Y/N)\n");
        scanf(" %c",&ch2);
        ch2=toupper(ch2);
        if(ch2=='N')
        flag=0;
        else
        flag=1;
        
    }
    return 0;
}