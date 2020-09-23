#include<stdio.h>
int main()
{
	int y0,m0,d0,y1,m1,d1,d;
	printf("input y0:");
	scanf("%d",&y0);
	printf("input m0:");
	scanf("%d",&m0);
	printf("input d0:");
	scanf("%d",&d0);
	printf("input y1:");
	scanf("%d",&y1);
	printf("input m1:");
	scanf("%d",&m1);
	printf("input d1:");
	scanf("%d",&d1);
        d=y1-y0;
	
	
	/* 2000.10.14  2001.10.16 结果不符 */
	/* 条件1: 月份差小于0,  d - 1 */
	/* 条件2: 月份差等于0 && 日份差小于0, d - 1 */
	/* 其余:  d */


	if(m1-m0<0)
	{
		printf("d=%d\n",d-1);
	}
	else if(m1-m0==0  &&  d1-d<0)
	{
		printf("d=%d\n",d-1);
	}

	else
	{
		printf("d=%d\n",d);
	}

}
