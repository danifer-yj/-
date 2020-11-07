#include "Btree.h"

//���򴴽�������
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
		printf("����%d������: ", ch);
		CreatBinaryTree(&((*T)->_left));
		printf("����%d���Һ���: ", ch);
		CreatBinaryTree((&(*T)->_right));
	}
}

//�������������
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
//����
void MiddleOrderBinaryTree(BTNode* root);
//����
void PostOrderBinaryTree(BTNode* root);
//�����������
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
