/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Definition for a binary tree node. */
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

/* 迭代解法 */
void in_iter(struct TreeNode *root, int *ret, int *returnSize)
{
	struct TreeNode *tmp[100] = {NULL};
	struct TreeNode *out = NULL;
	int n = 0;
	if (!root)
		return;

	tmp[n] = root;
	while(n >= 0)
	{
		/* 将左树依次压栈 */
		while (tmp[n]->left) {
			n++;
			tmp[n] = tmp[n-1]->left;
		}

		while (n >= 0) {
			/* 节点出栈 */
			ret[(*returnSize)] = tmp[n]->val;
			out = tmp[n];
			(*returnSize)++;
			n--;

			/* 如果出栈节点有有节点则压栈重复遍历左树 */
			if (out->right) {
				n++;
				tmp[n] = out->right;
				break;
			}
		}
	}
}

/* 递归解法 */
void in_order(struct TreeNode *root, int *ret, int *returnSize)
{
	if (root == NULL)
		return;
	in_order(root->left, ret, returnSize);
	ret[(*returnSize)++] = root->val;
	in_order(root->right, ret, returnSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *ret = NULL;
    ret = malloc(sizeof(int) * 100);
    *returnSize = 0;
	
    //in_order(root, ret, returnSize);
    in_iter(root, ret, returnSize);
    
    return ret;
}

struct TreeNode *create_node(int n)
{
	struct TreeNode *node = malloc(sizeof(struct TreeNode));

	memset(node, 0, sizeof(struct TreeNode));
	node->val = n;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int main(void)
{
	int i = 0, n = 0;
	int *ret = NULL;
	struct TreeNode *root = create_node(121);
	struct TreeNode *tmp = root;

	/* 创建十层二叉树节点 */
	for (i = 0; i < 10; i++)
	{
		tmp->left = create_node(i);
		tmp->right = create_node(i+1);
		if (i % 2)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}

	ret = inorderTraversal(root, &n);
	/* 打印中序遍历结果 */
	for (i = 0; i < n; i++)
	{
		printf("%d ", ret[i]);
	}
	printf("\n");



}

