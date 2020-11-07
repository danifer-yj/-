#include "queue.h"

void QueueInit(Queue* pq) {//创建一个队列
		//申请front和rear的空间
	pq = (Queue*)malloc(sizeof(Queue));
	if ((pq) == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	//申请头结点空间
	pq->_front = (QueueNode*)malloc(sizeof(QueueNode));
	pq->_rear = (QueueNode*)malloc(sizeof(QueueNode));
	if ((pq)->_front == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	pq->_front->_next = NULL;
	pq->_rear = pq->_front;

	return;
}

void QueueDestory(Queue* pq) {
	QueueNode* p = pq->_front;//记录队头
	while (p != NULL) {
		pq->_front = pq->_front->_next;//将队头变成下一个节点
		free(p);//释放原理记录的对头
		p = pq->_front;//接着记录新的队头
	}
	free(pq);//释放最后一个元素
}

//void QueuePush(Queue* pq, QUDataType x) {//入队
//	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode*));//创建节点
//	if (node == NULL) {//节点创建失败
//		puts("节点创建失败,导致入队失败\n");
//		return;
//	}
//	node->_data = x;
//	//将new节点插入到list中
//	node->_next = NULL;//将新插入节点的尾指正指向队列的尾指针
//	if (pq->_rear == NULL)
//		pq->_rear = pq->_front = node;
//	pq->_rear->_next = node;//将队列原来的尾指针指向新的元素
//	//改变队列的队尾_rear指针的值,即将_rear改变成new元素
//	pq->_rear = node;
//}

void QueuePush(Queue* queue, QUDataType elem) {
//	QueueNode* tmp = queue->_rear;
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	if (node == NULL) {
		return;
	}
	node->_data = elem;
	node->_next = NULL;
	queue->_rear->_next = node;
	queue->_rear = node;
//	queue->_rear = tmp;
}


void QueuePop(Queue* pq) {//出队
	QueueNode* tmp = NULL;
	if (QueueEmpty(pq)) {
		printf("队列为空\n");
		return;
	}
	tmp = pq->_front;
	//改变队头指针_front指针的指向
	pq->_front = pq->_front->_next;
	free(tmp);
}

QUDataType QueueFront(Queue* pq) {
	if (QueueEmpty(pq)) {
		return 0;
	}
	return pq->_front->_next->_data;

}
QUDataType QueueBack(Queue* pq)
{
	if (QueueEmpty(pq)) {
		return 0;
	}
	return pq->_rear->_data;
}

int QueueEmpty(Queue* pq) {
	if (pq->_rear == pq->_front)
		return 0;//没有元素
	else
		return 1;//有元素
}

void QueuePrint(Queue* pq) {
	QueueNode* p;
	if (QueueEmpty(pq)) {
		return;
	}
	for (p = pq->_front->_next; p != NULL; p = p->_next) {
		printf("%d->", p->_data);
	}
	printf("\n");
}

int QueueSize(Queue* pq);

void TestQueue() {
	Queue test;
	QueueInit(&test);
	QueuePush(&test, 1);
	QueuePush(&test, 2);
	QueuePush(&test, 3);
	QueuePush(&test, 4);
	QueuePrint(&test);
	QueuePop(&test);
	QueuePrint(&test);
}
