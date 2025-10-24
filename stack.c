#include<stdio.h>
#define max_size 3
int s[max_size],top=-1;
void display()
{  
	int i=0;
	printf("stack elements are :\n");
	for(i=top;i>=0;i--)
	{
		printf("%d ",s[i]);
        }
        printf("\n");	        
} 
void push(int item)
{ 
        
	if(top>=max_size)
	{
		printf("stack is full..\n");
	}
	else
	{
		top=top+1;
	        s[top]=item;
	        printf("%d is pushed successfully\n",item );
	}
}			
void pop()
{ 
        int item;
	if(top<0)
	{
		printf("stack is empty...\n");
	}
	else
	{	
	        item=s[top];
	        top=top-1;
	        printf("the poped element is :%d \n",item);
	      
	}
}	

int main()
{
	int choice,item;
	do
	
	{
		
		printf("1.push\n 2.pop\n 3.display\n 3.exit\n");
		printf("Enter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the element to push:");
			        scanf("%d",&item); 
			        push(item);
			        break;	
			case 2: pop();
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
