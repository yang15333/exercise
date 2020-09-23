/*
 * 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入:
	Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
输出:
合并后的树:
	     3
	    / \
	   4   5
	  / \   \
	 5   4   7
注意: 合并必须从两个树的根节点开始。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-binary-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

 /* Definition for a binary tree node. */
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 
#include <stdlib.h>
#include <string.h>

void first_loop(struct TreeNode* t1, struct TreeNode *t2, struct TreeNode *t3) {
	if (!t1 && !t2)
		return;

	t3->val += t1 ? t1->val : 0;
	t3->val += t2 ? t2->val : 0;


	struct TreeNode *t1_tmp = t1 ? t1->left : NULL;
	struct TreeNode *t2_tmp = t2 ? t2->left : NULL;
	
	if (t1_tmp || t2_tmp) {
		struct TreeNode *left = malloc(sizeof(struct TreeNode));
		memset(left, 0, sizeof(struct TreeNode));
		t3->left = left;
		first_loop(t1_tmp, t2_tmp, t3->left);
	}
	
	t1_tmp = t1 ? t1->right : NULL;
	t2_tmp = t2 ? t2->right : NULL;
	if (t1_tmp || t2_tmp) {
		struct TreeNode *right = malloc(sizeof(struct TreeNode));
		memset(right, 0, sizeof(struct TreeNode));
		t3->right = right;
		first_loop(t1_tmp, t2_tmp, t3->right);
	}

}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){	
	if (!t1 && !t2)
		return NULL;
	struct TreeNode *root = malloc(sizeof(struct TreeNode));
	memset(root, 0, sizeof(struct TreeNode));

	first_loop(t1, t2, root);
	
}


