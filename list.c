#define _CRT_SECURE_NO_WARNINGS 1 

#include "list.h"

void SListInit(SList* plist) {
	plist->_head = NULL;
}


SListNode* BuySListNode(SLTDataType x) {//创建节点
	SListNode* res = (SListNode*)malloc(sizeof(SListNode));//创建一个节点,所以开辟一个结构体的空间
	if (res == NULL) {
		printf("创建节点失败");
		return NULL;
	}
	res->_data = x;
	res->_next = NULL;
	return res;
}

void SListPushFront(SList* plist, SLTDataType x) {//头插
	SListNode* tmp = BuySListNode(x);//将给定的x值转化成节点
	if (tmp != NULL) {//会出现创建节点失败的情况
		tmp->_next = plist->_head;
		plist->_head = tmp;//plist->head变成了头结点
	}
}

void SListPopFront(SList* plist) {//头删
	if (plist->_head != NULL) {
		SListNode* ptmp = plist->_head;
		plist->_head = ptmp->_next;
		free(ptmp);
	}
}

SListNode* SListFind(SList* plist, SLTDataType x) {
	SListNode* tmp = plist->_head;
	while (tmp != NULL) {
		if (tmp->_data == x) {
			return tmp;
		}
		else {
			tmp = tmp->_next;
		}
	}
	return NULL;
}

// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x) {
	SListNode* tmp = BuySListNode(x);
	tmp->_next = pos->_next;//将新的tmp指向pos的下一个元素
	pos->_next = tmp;//pos指向新的tmp元素
}

// 在pos的前面进行插入
void SListEraseAfter(SListNode* pos) {//删除pos+1位置的节点
	SListNode* tmp = pos->_next;
	pos->_next = pos->_next->_next;
	free(tmp);//将pos->_next元素释放
}

void SListRemove(SList* plist, SLTDataType x) {//删除值为x的节点
	if (plist->_head != NULL && plist->_head->_data == x) {//第一个节点就是我们要删的值
		SListPopFront(plist);
	}
	if (plist == NULL) {
		return;
	}
	SListNode* ph = plist->_head;
	SListNode* pt = ph->_next;
	while (pt != NULL) {
		if (pt->_data == x) {
			pt = pt->_next;//pt已经让开了
			//此时ph和pt之间的元素就是我们要删除的元素,即删除ph后面的元素
			SListEraseAfter(ph);
			ph->_next = pt;//将ph和pt连接起来
			continue;
		}
		pt = pt->_next;
		ph = ph->_next;
	}
}

void SListPrint(SList* plist) {
	SListNode* pt = plist->_head;
	while (pt != NULL) {
		printf("%d->", pt->_data);
		pt = pt->_next;
	}
	printf("\n");
}

void SListDestory(SList* plist) {
	if (plist->_head != NULL) {
		SListNode* phead = plist->_head;		//将头节点记录下来
		while (phead != NULL) {
			SListNode* t = phead;		//记录下头节点
			phead = phead->_next;		//phead变成phead的下一个节点
			free(t);		//将记录下来的头节点释放
		}
		plist->_head = NULL;//
	}
}
