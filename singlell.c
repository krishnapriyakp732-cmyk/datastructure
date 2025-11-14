#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *header=NULL;
/*void createnode()
{
	
}*/
void insertAtFront(int item)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->link = NULL;
	if(header==NULL)
	{	
		header=newnode;
	}
	else
	{	
		newnode->link=header;
		header=newnode;
	}		
}
void insertAtEnd(int item)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->link = NULL;
	if(header==NULL)
	{
		header=newnode;
	}
	else
	{
		struct node *ptr;
		ptr=header;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=newnode;
	}
}
void insertAtAny(int key,int item)
{
	struct node *ptr,*ptr1;
	ptr=ptr1=header;
	while(ptr!=NULL && ptr->data !=key )
	{
		ptr1=ptr;
		ptr=ptr->link;
	}
	if(ptr == NULL)
	{
        	printf("Key not found,Insertion not possible");
	}
	else
	{
		struct node *newnode;
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data = item;
		newnode->link = ptr;	
		ptr1->link=newnode;
	}		
}

void DeleteAtFront()
{
	struct node *ptr;
	if(header!=NULL)
	{
		
		ptr=header;
		header=header->link;
		free(ptr);	
	}
	else
	{
		
		printf("Empty list,Deletion is not possible....\n");
	}
}
void DeleteAtEnd()
{
	struct node *ptr,*ptr1;
	ptr=ptr1=header;
	if(header!=NULL)
	{
		while(ptr->link!=NULL)
		{	
			ptr1=ptr;
			ptr=ptr->link;
		}
		printf("deleted element is %d",ptr->data);
		ptr1->link=NULL;
		free(ptr);
	}
}
void DeleteAtAny(int key)
{
	struct node *ptr,*ptr1;
	ptr=header;
	ptr1=NULL;
	while(ptr!=NULL && ptr->data !=key )
	{
		ptr1=ptr;
		ptr=ptr->link;
	}
	if(ptr == NULL)
	{
		printf("key not found,DEletion not possible");
		
	}	
	else
	{
		printf("Deleted element is %d",ptr->data);
		if(ptr1 != NULL)
		{
			ptr1->link=ptr->link;
			
		}
		else
		{
			header=ptr->link;
		}
		free(ptr);
		
	
	}
}

void traverselist()
{	
	struct node *ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	
}
int main()
{
    int choice,item,key;
    do 
    {	
        printf("\n1.insert at Front\n2.insert at End\n3.insert at Any\n4.delete at front\n5.delete at end  \n6.delete at any\n7.display\n8.exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {	
                case 1:
			printf("Enter the element to insert at Front: ");
                        scanf("%d", &item);
                        insertAtFront(item);
                        break;
               case 2:
               		printf("Enter the element to insert at End: ");
                      	scanf("%d", &item);
                      	insertAtEnd(item);
                      	break;
               case 3:
               		printf("enter the key :");
                      	scanf("%d", &key);
                      	printf("Enter the element to insert at Any node: ");
                      	scanf("%d", &item);
                     	insertAtAny(key,item);
                      	break;
               case 4:
               		DeleteAtFront();
             	      	break;
               case 5:
               		DeleteAtEnd();
            	      	break;
               case 6:
               		printf("enter the key :");
                      	scanf("%d", &key);
               		DeleteAtAny(key);
            	      	break;
               case 7:
               		printf("The elements in list:\n");
                      	traverselist();
                      	break;
               case 8:
               		break;
               default: 
               		printf("Enter the correct choice...\n");
               		break;
              
        }

    }
    while (choice!=8);
  return (0);
}	
		


	 
