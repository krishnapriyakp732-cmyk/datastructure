#include<stdio.h>
int main()
{
	int ary[50],n,i,sum=0;
        printf("enter the size of array:");
        scanf("%d",&n);
        if(n>50)
        {
        	printf("error! no of value is greater then array size...);
        }
        else
        {	
                printf("enter the values for array:");
        	for(i=0;i<n;i++)
                {    
        		scanf("%d",&ary[i]);
                }
                for(i=0;i<n;i++)  
                {
                	sum=sum+ary[i];
                }           
                printf("sum of %d numbers are %d",n,sum);
        }    
	return 0;
 }       
