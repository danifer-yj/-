#include "queue.h"

void QueueInit(Queue* pq) {//����һ������
		//����front��rear�Ŀռ�
	pq = (Queue*)malloc(sizeof(Queue));
	if ((pq) == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	//����ͷ���ռ�
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
	QueueNode* p = pq->_front;//��¼��ͷ
	while (p != NULL) {
		pq->_front = pq->_front->_next;//����ͷ�����һ���ڵ�
		free(p);//�ͷ�ԭ���¼�Ķ�ͷ
		p = pq->_front;//���ż�¼�µĶ�ͷ
	}
	free(pq);//�ͷ����һ��Ԫ��
}

//void QueuePush(Queue* pq, QUDataType x) {//���
//	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode*));//�����ڵ�
//	if (node == NULL) {//�ڵ㴴��ʧ��
//		puts("�ڵ㴴��ʧ��,�������ʧ��\n");
//		return;
//	}
//	node->_data = x;
//	//��new�ڵ���뵽list��
//	node->_next = NULL;//���²���ڵ��βָ��ָ����е�βָ��
//	if (pq->_rear == NULL)
//		pq->_rear = pq->_front = node;
//	pq->_rear->_next = node;//������ԭ����βָ��ָ���µ�Ԫ��
//	//�ı���еĶ�β_rearָ���ֵ,����_rear�ı��newԪ��
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


void QueuePop(Queue* pq) {//����
	QueueNode* tmp = NULL;
	if (QueueEmpty(pq)) {
		printf("����Ϊ��\n");
		return;
	}
	tmp = pq->_front;
	//�ı��ͷָ��_frontָ���ָ��
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
		return 0;//û��Ԫ��
	else
		return 1;//��Ԫ��
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
