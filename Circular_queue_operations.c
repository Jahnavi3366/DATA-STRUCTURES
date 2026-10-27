#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue()
{
    if((front==0&&rear==MAX-1)||(front==rear+1))
    {
        printf("Queue Overflow\n");
        return;
    }
    int num;
    printf("Enter the element: ");
    scanf("%d",&num);
    if (front == -1 && rear == -1)
    {
        front=0;
        rear=0;
    }
    else if(rear==MAX-1&&front!=0)
    {
        rear=0;
    }
    else
    {
        rear=rear+1;
    }
    queue[rear]=num;
    printf("Inserted: %d\n", num);
}
int dequeue()
{
    int val;
    if(front==-1)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    val=queue[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==MAX-1)
    {
        front=0;
    }
    else
    {
        front++;
    }
    return val;
}
void display()
{
    int i;

    if(front==-1)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements (FRONT to REAR) are: \n");
    i=front;
    while (1)
    {
        printf("Index= %d, Value= %d\n",i,queue[i]);
        if(i==rear)
            break;
        i=(i+1)%MAX;
    }
}

int main()
{
    int choice,val;
    printf("\n1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                val = dequeue();

                if (val != -1)
                    printf("Deleted element: %d\n", val);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting!....\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
