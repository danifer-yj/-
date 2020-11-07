#define _CRT_SECURE_NO_WARNINGS 1 
#include "seqlist.h" 
#include "list.h"
#include "HeadList.h"
#include "Stack.h"
#include "queue.h"
#include "BTree.h"
//void Test() 
//{ 
// SeqList *List; 
// InitSeqList(&List); 
// PushBack(&List, 1); 
// PushBack(&List, 2); 
// PushBack(&List, 3); 
// PushBack(&List, 4); 
// PushBack(&List, 5); 
// PopBack(&List); 
// printf("%d ", Find(&List, 2)); 
// PrintfSeqList(&List); 
//} 

void Test2()
{
	SeqList List;
	InitSeqList(&List);
	PushBack(&List, 1);
	PushBack(&List, 2);
	PushBack(&List, 3);
	PushBack(&List, 4);
	PushBack(&List, 5);
	PushFront(&List, 5);
	PushFront(&List, 2);
	PushFront(&List, 3);
	//PopFront(&List); 
	RemoveAll(&List, 5);
	//BubbleSort(&List); 
	//BinarySearch(&List, 3); 
	PrintfSeqList(&List);
}

void TestList() {
	SList test;

	SListInit(&test);

	SListPushFront(&test, 1);
	SListPushFront(&test, 2);
	SListPushFront(&test, 3);
	SListNode* tmp = test._head->_next->_next;
	SListInsertAfter(tmp, 4);
	SListInsertAfter(tmp, 4);
	SListInsertAfter(tmp, 5);
	SListInsertAfter(tmp, 6);
	//¥Ú”°
	SListPrint(&test);
	SListRemove(&test, 6);
	SListPrint(&test);
	//¥›ªŸ
	SListDestory(&test);
	SListPrint(&test);
}

void TestHeadList() {
	List test;
	ListInit(&test);
	ListPushBack(&test, 1);
	ListPushBack(&test, 1);
	ListPushBack(&test, 2);
	ListPushBack(&test, 3);
	ListPushBack(&test, 4);
	ListPushBack(&test, 5);
	ListPushBack(&test, 5);
	ListPushFront(&test, 6);
	ListPushFront(&test, 7);
	ListPushFront(&test, 8);
	ListPushFront(&test, 9);
	ListPrint(&test);
	ListRemove(&test, 5);
	ListPrint(&test);
}

int main()
{
	//Test2();
	//TestList();
	//TestHeadList();
	//TestStack();
	//TestQueue();
	TestBinaryTree();
	system("pause\n");
	return 0;
}

