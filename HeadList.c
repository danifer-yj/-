#include "HeadList.h"

void ListInit(List* plist) {//�����ʼ��
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

void ListDestory(List* plist) {//����ѭ������
	ListNode* pt = plist->_head->_next;
	while (pt != plist->_head) {//��pt����plist->_headʱ,plist->_prev����plist���һ���ڵ�
		pt = pt->_next;
		free(pt->_prev);
	}
	//��ʱ,ֻʣ��ͷ�ڵ���,�ͽ�ͷ�ڵ��_next��_prevָ��ͷ�ڵ㱾��
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

void ListPushBack(List* plist, LTDataType x) {//β��
	ListNode* pt = (ListNode*)malloc(sizeof(ListNode));//�Ƚ�x�����ɽڵ�
	if (pt == NULL) {
		printf("�����ڵ�ʧ��,β��ʧ��");
		return;
	}
	pt->_data = x;
	plist->_head->_prev->_next = pt;//���һ��Ԫ�غ�ָ��ָ��pt
	pt->_prev = plist->_head->_prev;//pt��ǰָ��ָ��plist�����һ��Ԫ��
	pt->_next = plist->_head;//��ʱpt�����һ��Ԫ��,���ĺ�ָ��ָ��plist->_head
	plist->_head->_prev = pt;//��ʱ,pt�����һ��Ԫ��,plist->_head->_prevָ��pt
}

void ListPopBack(List* plist) {//βɾ
	//��¼��β��Ԫ��,��Ϊ���Ҫ��β��Ԫ���ͷ�
	ListNode* pt = plist->_head->_prev;
	//pt��ǰһ��Ԫ��ָ��ͷ(��pt->_next)
	pt->_prev->_next = pt->_next;
	//ͷָ���ǰָ�� ָ�� pt��ǰһ��Ԫ��
	pt->_next->_prev = pt->_prev;
	//�ͷ�pt
	free(pt);
}

void ListPushFront(List* plist, LTDataType x) {//ͷ��,  ��node���뵽head����
	//�����ڵ�
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) {
		printf("�����ڵ�ʧ��,ͷ��ʧ��\n");
		return;
	}
	node->_data = x;//���ڵ㸳ֵ
	node->_next = plist->_head->_next;//node��_nextָ��ָ��ͷ�ڵ����һ��Ԫ��
	node->_prev = plist->_head;//��node��_prevָ��plist��ͷ
	plist->_head->_next->_prev = node;		//head����һ��Ԫ�ص�ǰָ��ָ���½ڵ�node
	plist->_head->_next = node;//head��nextָ�����ı���Ϊ��head��nextָ��ñ��˾��Ҳ���head��һ��Ԫ�ص�ǰָ����	
}

void ListPopFront(List* plist) {//ͷɾ
	ListNode* pt = plist->_head->_next;//��¼ͷ������һ���ڵ�
	plist->_head->_next = pt->_next;//�����head�ڵ���¸��ڵ������¸��ڵ�
	pt->_next->_prev = plist->_head;//head�ڵ�����¸��ڵ��ǰָ��ָ��head�ڵ�
	free(pt);
}

ListNode* ListFind(List* plist, LTDataType x) {//����xֵ
	//_headͷ�ڵ��ǲ�����ֵ��,����Ҫ��ͷ������һ���ڵ㿪ʼ����
	ListNode* pt = plist->_head->_next;
	while (pt != plist->_head) {//��pt��plist->_head���,��ʱ�������Ѿ��������
		if (pt->_data == x)
			return pt;//���ص���һ��struct�ڵ�
		pt = pt->_next;
	}
	return NULL;//������������û�з���ֵ,��û��xֵ,��ʱ�ͷ���NULL
}


// ��pos��ǰ����в���
void ListInsertfront(ListNode* pos, LTDataType x) {
	//�Ƚ����ڵ�
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) {//�ڵ㴴��ʧ��,ֱ�ӷ���,��������
		printf("�����ڵ�ʧ��,ǰ��ʧ��\n");
		return;
	}
	node->_data = x;
	pos->_prev->_next = node;//pos��prev�ڵ��nextָ��ָ��node
	node->_prev = pos->_prev;//node��ǰָ��ָ��pos��ǰ�ڵ�
	node->_next = pos;//node��nextָ��ָ��pos�ڵ�
	pos->_prev = node;//pos��ǰָ��ָ��node�ڵ�
}

//��pos�ĺ������
void ListInsertback(ListNode* pos, LTDataType x) {
	//�Ƚ����ڵ�
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) {//�ڵ㴴��ʧ��,ֱ�ӷ���,��������
		printf("�����ڵ�ʧ��,ǰ��ʧ��\n");
		return;
	}
	node->_data = x;
	node->_next = pos->_next;//node��nextָ��ָ��pos����һ���ڵ�
	pos->_next->_prev = node;//pos��next�ڵ��prevָ��ָ��node
	pos->_next = node;//pos
	node->_prev = pos;
}

// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos) {
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}

void ListRemove(List* plist, LTDataType x) {//ɾ������ֵΪx�Ľڵ�
	ListNode* pt = plist->_head->_next;
	while (pt != plist->_head) {
		if (pt->_data == x) {
			pt->_next->_prev = pt->_prev;
			pt->_prev->_next = pt->_next;
			ListNode* node = pt;
			pt = pt->_next;
			free(node);
			continue;
		}
		pt = pt->_next;
	}
}

void ListPrint(List* plist) {
	ListNode* pt = plist->_head->_next;
	while (pt != plist->_head) {
		printf("%d->", pt->_data);
		pt = pt->_next;
	}
	printf("\n");
}
