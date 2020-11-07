#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int BTDataType;
typedef struct BTNode
{
	BTDataType _data;
	struct BTNode* _left;
	struct BTNode* _right;
}BTNode;

//���򴴽�������
void CreatBinaryTree(BTNode** T);
//�������������
void PreOrderBinaryTree(BTNode* T);
//����
void MiddleOrderBinaryTree(BTNode* root);
//����
void PostOrderBinaryTree(BTNode* root);
//�����������
int TreeDeep(BTNode* root);


// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ����
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
// �ǵݹ����
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);
void TestBinaryTree();

#endif/*__BTREE_H__*/