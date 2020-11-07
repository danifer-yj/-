#include "HeadList.h"

void ListInit(List* plist) {//链表初始化
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

void ListDestory(List* plist) {//销毁循环链表
	ListNode* pt = plist->_head->_next;
	while (pt != plist->_head) {//当pt等于plist->_head时,plist->_prev就是plist最后一个节点
		pt = pt->_next;
		free(pt->_prev);
	}
	//此时,只剩下头节点了,就将头节点的_next和_prev指向头节点本身
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

void ListPushBack(List* plist, LTDataType x) {//尾插
	ListNode* pt = (ListNode*)malloc(sizeof(ListNode));//先将x创建成节点
	if (pt == NULL) {
		printf("创建节点失败,尾插失败");
		return;
	}
	pt->_data = x;
	plist->_head->_prev->_next = pt;//最后一个元素后指针指向pt
	pt->_prev = plist->_head->_prev;//pt的前指针指向plist的最后一个元素
	pt->_next = plist->_head;//此时pt是最后一个元素,它的后指针指向plist->_head
	plist->_head->_prev = pt;//此时,pt是最后一个元素,plist->_head->_prev指向pt
}

void ListPopBack(List* plist) {//尾删
	//记录下尾部元素,因为最后要将尾部元素释放
	ListNode* pt = plist->_head->_prev;
	//pt的前一个元素指向头(即pt->_next)
	pt->_prev->_next = pt->_next;
	//头指针的前指针 指向 pt的前一个元素
	pt->_next->_prev = pt->_prev;
	//释放pt
	free(pt);
}

void ListPushFront(List* plist, LTDataType x) {//头插,  将node插入到head后面
	//创建节点
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) {
		printf("创建节点失败,头插失败\n");
		return;
	}
	node->_data = x;//将节点赋值
	node->_next = plist->_head->_next;//node的_next指针指向头节点的下一个元素
	node->_prev = plist->_head;//将node的_prev指向plist的头
	plist->_head->_next->_prev = node;		//head的下一个元素的前指针指向新节点node
	plist->_head->_next = node;//head的next指针最后改变因为若head的next指针该变了就找不到head下一个元素的前指针了	
}

void ListPopFront(List* plist) {//头删
	ListNode* pt = plist->_head->_next;//记录头结点的下一个节点
	plist->_head->_next = pt->_next;//链表的head节点的下个节点变成下下个节点
	pt->_next->_prev = plist->_head;//head节点的下下个节点的前指针指向head节点
	free(pt);
}

ListNode* ListFind(List* plist, LTDataType x) {//查找x值
	//_head头节点是不保存值的,所以要从头结点的下一个节点开始查找
	ListNode* pt = plist->_head->_next;
	while (pt != plist->_head) {//若pt和plist->_head相等,此时就链表已经遍历完成
		if (pt->_data == x)
			return pt;//返回的是一个struct节点
		pt = pt->_next;
	}
	return NULL;//若遍历完链表还没有返回值,就没有x值,此时就返回NULL
}


// 在pos的前面进行插入
void ListInsertfront(ListNode* pos, LTDataType x) {
	//先建立节点
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) {//节点创建失败,直接返回,结束函数
		printf("创建节点失败,前插失败\n");
		return;
	}
	node->_data = x;
	pos->_prev->_next = node;//pos的prev节点的next指针指向node
	node->_prev = pos->_prev;//node的前指针指向pos的前节点
	node->_next = pos;//node的next指针指向pos节点
	pos->_prev = node;//pos的前指针指向node节点
}

//在pos的后面插入
void ListInsertback(ListNode* pos, LTDataType x) {
	//先建立节点
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL) {//节点创建失败,直接返回,结束函数
		printf("创建节点失败,前插失败\n");
		return;
	}
	node->_data = x;
	node->_next = pos->_next;//node的next指针指向pos的下一个节点
	pos->_next->_prev = node;//pos的next节点的prev指针指向node
	pos->_next = node;//pos
	node->_prev = pos;
}

// 删除pos位置的节点
void ListErase(ListNode* pos) {
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}

void ListRemove(List* plist, LTDataType x) {//删除所有值为x的节点
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
