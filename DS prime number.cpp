#include<stdio.h>
int main()
{
	int i,n,m=0,flag=0;
	printf("enter the number:");
	scanf("%d",&n);
	m=n/2;
	{
		for(i=2;i<=m;i++)
		{
			if(n%i==0)
			{
				printf("the given number is a prime number:");
				flag=1;
				break;
			}
		}
		if(flag==0)
		printf("the given number is not a prime number:");
		return 0;
	}
}
