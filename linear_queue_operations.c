#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue()
{
    int item;
    if (rear==MAX-1)
    {
        printf("Queue Overflow");
        return;
    }
    printf("Enter number to be inserted: ");
    scanf("%d",&item);
    if(front==-1)
        front=0;
    rear=rear+1;
    queue[rear]=item;
    printf("%d successfully inserted",queue[rear]);
}
int dequeue()
{
    if((front==-1)||(front>rear))
    {
        printf("Queue Underflow");
        return 0;
    }
    else
    {
        int value=queue[front];
        front++;
        printf("%d is deleted successfully",value);
    }
}
void display()
{
    int i;
    if((front==-1)||(front>rear))
    {
        printf("Queue Underflow");
        return;
    }
    printf("QUEUE ELEMENTS are:");
    for(i=front;i<=rear;i++)
    {
        printf("\n%d",queue[i]);
    }
}
int main()
{
    int choice,item;
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    while(1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid Choice");
        }
    }
    return 0;
}
