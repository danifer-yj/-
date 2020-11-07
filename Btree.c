#include "Btree.h"

//先序创建二叉树
void CreatBinaryTree(BTNode** T) {
	BTDataType ch;
	scanf("%d", &ch);
	if (ch == -1) {
		*T = NULL;
		return;
	}
	else {
		*T = (BTNode*)malloc(sizeof(BTNode));
		(*T)->_data = ch;
		printf("输入%d的左孩子: ", ch);
		CreatBinaryTree(&((*T)->_left));
		printf("输入%d的右孩子: ", ch);
		CreatBinaryTree((&(*T)->_right));
	}
}

//先序遍历二叉树
void PreOrderBinaryTree(BTNode* T) {
	if (T == NULL)
	{
		return;
	}
	else
	{
		printf("%d ", T->_data);
		PreOrderBinaryTree(T->_left);
		PreOrderBinaryTree(T->_right);
	}
}
//中序
void MiddleOrderBinaryTree(BTNode* root);
//后序
void PostOrderBinaryTree(BTNode* root);
//二叉树的深度
int TreeDeep(BTNode* root) {
	int deep = 0;
	if (root != NULL) {
		int leftdeep = TreeDeep(root->_left);
		int rightdeep = TreeDeep(root->_right);
		deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
	}
}

void TestBinaryTree(){
	BTNode* T;
	CreatBinaryTree(&T);
	PreOrderBinaryTree(T);
}
