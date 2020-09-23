#include<stdio.h>
int main()
{
       int a,b,c, tmp;
	printf("input a:");
	scanf("%d",&a);
	printf("input b:");
	scanf("%d",&b);
	printf("input c:");
	scanf("%d",&c);


	/* a > c的条件式 本身会产生一个结果
	 * 条件为真 结果为1,
	 * 条件为假 结果为0。
	 * 所以a > c > b 实际上会先计算 a > c 的结果
	 * 然后用 0(假)或1(真)再跟b比较大小 */

        /* 思路: 先找到三数中最大的,去掉最大数,再找剩余两数中最大的,既可排出大小顺序*/	
	if (a>b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	if(b>c)
	{
		tmp = b;
		b = c;
		c = tmp;
	}

	if(a>b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	

	printf("%d %d %d\n",a,b,c);
}

