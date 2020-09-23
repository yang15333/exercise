#include <stdio.h>
/* 
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.
*/


int numSquares2(int n)
{
	static int cnt = 0;

	return 0;
}


/* 错误解法: 原因只考虑了局部最优解，用递归将原始数据逐步分解
 * 如输入12 时 该算法会输出 9 + 1 + 1 + 1
 * 但最优解为 4 + 4 + 4 */
int numSquares(int n)
{
	int i = 1;
	int tmp = 0;
	if (n == 0) {
		return 0;
	}

	while (1) {
		tmp = i * i;
		if (n > tmp) {
			i++;
		}
	     	else if (n == tmp) {
			break;
		}
		else {
			i--;
			break;
		}	
	}

	tmp = i * i;
	n -= tmp;
	if (n > 0) {
		printf("%d + ", tmp);
	}
	else {
		printf("%d = ", tmp);
	}
	return 1 + numSquares(n);
}

int main(void)
{
	int n = 0;
	int ret = 0;

	printf("input n:");
	scanf("%d", &n);
	ret = numSquares(n);
	printf("%d\n", n);
	printf("result:%d\n", ret);
	
	return 0;
}
