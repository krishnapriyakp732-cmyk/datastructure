#include<stdio.h>
#define max_size 1
int queue[max_size],rear=-1,front=-1;
void display()
{  
	int i;
	if(front==-1)
	{
		printf(" Queue is empty\n");
		return;
	}
	printf("Queue elements are:");
	for(i=front;i<=rear;i++)
	{
		printf("%d ",queue[i]);
        }
        printf("\n");	        
} 
void enqueue(int item)
{ 
        
	if(rear==max_size-1)
	{
		printf("Queue is full..\n");
		return;
	}
	if(front==-1)
	front=0;
	
	rear++;
	queue[rear]=item;
	printf("%d is enqueued successfully\n",item );
	
}			
void dequeue()
{ 
        if(front==-1  || front>rear)
	{
		printf("The last element is Dequeued then Queue is empty...\n");
		return;
	}
	int item=queue[front];
	front++;
	printf("the dequeued element is :%d \n",item);
		
	if(front>rear)   
	{
		front=-1;
		rear=-1;   
	   
	}
}	

int main()
{
	int choice,item;
	do
	
	{
		
		printf("1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n");
		printf("Enter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the element to enqueue:");
			        scanf("%d",&item); 
			        enqueue(item);
			        break;	
			case 2: dequeue();
			        break;
			case 3: display();
			        break;
			case 4: break; 
		        default: printf("Enter the correct choice.");
		                 break;
		}
	}
	while(choice!=4);		          
        return 0;	
}     
