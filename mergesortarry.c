#include<stdio.h>
void display(int ary[],int size)
{
	printf("array elements are:");
	for(int i=0;i<size;i++)
	{
		printf("%d ",ary[i]);
        }
        printf("\n");
}
void sort(int ary[],int size)
{
	int temp,i,j;
	for(i=0;i<size;i++)
	{	
		for(j=i+1;j<size;j++)
		{ 
			if(ary[i]>ary[j])
			{
				temp=ary[i];
				ary[i]=ary[j];
				ary[j]=temp;
		        }  
		}       
	}
}		
void merge(int ary1[],int ary2[],int ary3[],int size1,int size2)	
{
        int j,i; 
	for(i=0;i<size1;i++)
	{	
		ary3[i]=ary1[i];
        }
        for( j=0;j<size2;j++)
        {
        	ary3[i]=ary2[j];
        	i++;
        }
}        	
int main()
{		
	int ary1[10],ary2[10],ary3[20],m,n,i,size;
	printf("enter the size of 1st array:");
	scanf("%d",&n);
	if(n>=100)
        {
        	printf("error...");
       
     
        }        
        else 
        {
                printf("enter the values of 1 st array:");
                for(i=0;i<n;i++)
                {
                	scanf("%d",&ary1[i]);
        	}
       } 		
        printf("enter the size of  2nd array:\n");
        scanf("%d",&m) ;      
        if(m>=100)
        {
        	printf("error...");
       
     
        }        
        else 
        {
                printf("enter the values of 1 st array:");
                for(i=0;i<m;i++)
                {
                	scanf("%d",&ary2[i]);
        	}
        	display(ary2,m);
        } 	
         printf("sorted 1st \n")  ;
         sort(ary1,n);  
         display(ary1,n);
         printf("sorted 2nd\n ")  ;
         sort(ary2,m);
         display(ary2,m);
         size=n+m;
         printf("merged \n");
         merge(ary1,ary2,ary3,n,m);
         sort(ary3,size);
         display(ary3,size);
         
                        
         return 0;
}	
