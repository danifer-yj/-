#pragma once
#ifndef __HEADLIST_H__
#define __HEADLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2����ͷ˫��ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
typedef struct List
{
	ListNode* _head;
}List;
void ListInit(List* plist);
void ListDestory(List* plist);
void ListPushBack(List* plist, LTDataType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);
ListNode* ListFind(List* plist, LTDataType x);

// ��pos��ǰ����в���
void ListInsertfront(ListNode* pos, LTDataType x);
//��pos�ĺ������
void ListInsertback(ListNode* pos, LTDataType x);
// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);
void ListPrint(List* plist);

#endif/*__HEADLIST_H__*/