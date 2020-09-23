/*
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sudoku-solver
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printSudoku(char (*board)[9])
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void createSudoku(char (*board)[9])
{
	int i, j;
	char tmp[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int rd = 0;
	srand(time(NULL));

	for (i = 0; i < 9; i++)
	{
		rd = rand() % 9;
		while (!tmp[rd])
			rd = rand() % 9;
		board[0][i] = tmp[rd];
		tmp[rd] = 0;
	}

	for (i = 1; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			board[i][j] = '.';
		}
	}
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
	
}

int main(void)
{	
	char board[9][9] = {0};
	createSudoku(board);
	printSudoku(board);
	return 0;
}
