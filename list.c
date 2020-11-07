#define _CRT_SECURE_NO_WARNINGS 1 

#include "list.h"

void SListInit(SList* plist) {
	plist->_head = NULL;
}


SListNode* BuySListNode(SLTDataType x) {//�����ڵ�
	SListNode* res = (SListNode*)malloc(sizeof(SListNode));//����һ���ڵ�,���Կ���һ���ṹ��Ŀռ�
	if (res == NULL) {
		printf("�����ڵ�ʧ��");
		return NULL;
	}
	res->_data = x;
	res->_next = NULL;
	return res;
}

void SListPushFront(SList* plist, SLTDataType x) {//ͷ��
	SListNode* tmp = BuySListNode(x);//��������xֵת���ɽڵ�
	if (tmp != NULL) {//����ִ����ڵ�ʧ�ܵ����
		tmp->_next = plist->_head;
		plist->_head = tmp;//plist->head�����ͷ���
	}
}

void SListPopFront(SList* plist) {//ͷɾ
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

// ��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x) {
	SListNode* tmp = BuySListNode(x);
	tmp->_next = pos->_next;//���µ�tmpָ��pos����һ��Ԫ��
	pos->_next = tmp;//posָ���µ�tmpԪ��
}

// ��pos��ǰ����в���
void SListEraseAfter(SListNode* pos) {//ɾ��pos+1λ�õĽڵ�
	SListNode* tmp = pos->_next;
	pos->_next = pos->_next->_next;
	free(tmp);//��pos->_nextԪ���ͷ�
}

void SListRemove(SList* plist, SLTDataType x) {//ɾ��ֵΪx�Ľڵ�
	if (plist->_head != NULL && plist->_head->_data == x) {//��һ���ڵ��������Ҫɾ��ֵ
		SListPopFront(plist);
	}
	if (plist == NULL) {
		return;
	}
	SListNode* ph = plist->_head;
	SListNode* pt = ph->_next;
	while (pt != NULL) {
		if (pt->_data == x) {
			pt = pt->_next;//pt�Ѿ��ÿ���
			//��ʱph��pt֮���Ԫ�ؾ�������Ҫɾ����Ԫ��,��ɾ��ph�����Ԫ��
			SListEraseAfter(ph);
			ph->_next = pt;//��ph��pt��������
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
		SListNode* phead = plist->_head;		//��ͷ�ڵ��¼����
		while (phead != NULL) {
			SListNode* t = phead;		//��¼��ͷ�ڵ�
			phead = phead->_next;		//phead���phead����һ���ڵ�
			free(t);		//����¼������ͷ�ڵ��ͷ�
		}
		plist->_head = NULL;//
	}
}
