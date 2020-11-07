#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front; // 队头
	QueueNode* _rear; // 队尾
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

//创建一个队列节点
QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);

QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

void QueuePrint(Queue* pq);
void TestQueue();

#endif/*__QUEUE_H__*/