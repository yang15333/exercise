#include<stdio.h>
int main()
{

	int a,b,c;
        printf("input a:");
        scanf("%d",&a);
	printf("input b:");
	scanf("%d",&b);
	printf("input c:");
	scanf("%d",&c);


	if(a>=b  && a>=c)
	{
		printf("%d\n",a);
	}

        else if(b>=a  &&  b>=c)
	{
		printf("%d\n",b);
	}

	else
	{
		printf("%d\n",c);
	}

}
