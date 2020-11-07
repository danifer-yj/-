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

//先序创建二叉树
void CreatBinaryTree(BTNode** T);
//先序遍历二叉树
void PreOrderBinaryTree(BTNode* T);
//中序
void MiddleOrderBinaryTree(BTNode* root);
//后序
void PostOrderBinaryTree(BTNode* root);
//二叉树的深度
int TreeDeep(BTNode* root);


// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
void BinaryTreeDestory(BTNode** root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
int BinaryTreeLevelKSize(BTNode* root, int k);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// 遍历
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);
// 非递归遍历
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);
void TestBinaryTree();

#endif/*__BTREE_H__*/