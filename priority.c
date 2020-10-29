#include <stdio.h>
#include <stdlib.h>
void insert(int);
void delete(int);
void sort(int);
void display();
int pq[10];
int f=-1,r=-1;
void main()
{
    int n,c;
    printf("1.Insert an element\n");
    printf("2.Delete an element\n");
    printf("3.Display queue elements\n");
    pritnf("4.exit\n");
    while (1)
    {
        printf("Enter your choice : ");    
        scanf("%d",&c);
        switch (c)
        {
        case 1: 
            printf("Enter value to insert: ");
            scanf("%d",&n);
            insert(n);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d",&n);
            delete(n);
            break;
        case 3: 
            display();
            break;
        case 4: 
            break;
        default: 
            printf("Invalid choice");
        }
    }
}
void insert(int data)
{
    if (r>=10-1)
    {
        printf("Queue overflow\n");
        return;
    }
    if ((f==-1)&&(r==-1))
    {
        f++;
        r++;
        pq[r]=data;
        return;
    }    
    else
    sort(data);
    r++;
}
void sort(int data)
{
    int i,j;
    for (i=0;i<=r;i++)
    {
        if (data>=pq[i])
        {
            for (j=r+1;j>i;j--)
            {
                pq[j]=pq[j-1];
            }
            pq[i]=data;
            return;
        }
    }
    pq[i]=data;
}
void delete(int data)
{
    int i;
    if ((f==-1)&&(r==-1))
    {
        printf("Queue underflow\n");
        return;
    }
    for (i=0;i<=r;i++)
    {
        if (data==pq[i])
        {
            for (;i<r;i++)
            {
                pq[i]=pq[i+1];
            }
        pq[i]=-99;
        r--;
        if(r==-1) 
            f=-1;
        return;
        }
    }
    printf("%d not found in queue to delete\n", data);
}
void display()
{
    if((f==-1)&&(r==-1))
    {
        printf("Queue is empty\n");
        return;
    }
    for(;f<=r;f++)
    {
        printf(" %d\n",pq[f]);
    }
    f=0;
}