#define _CRT_SECURE_NO_WARNINGS 1 

#ifndef __SEQLIST_H__ 
#define __SEQLIST_H__ 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 

typedef int DataType;

#define DEFAULT_SZ 3 
#define INC_SZ 2 

typedef struct SeqList
{
	DataType* data;
	int sz;
	int capacity;
}SeqList, * pSeqList;

void InitSeqList(pSeqList pList);
void PushBack(pSeqList pList, DataType d);
void PopBack(pSeqList pList);
void PushFront(pSeqList pList, DataType d);
void PopFront(pSeqList pList);
int Find(pSeqList pList, DataType d);
void Remove(pSeqList pList, DataType d);
void RemoveAll(pSeqList pList, DataType d);
void BubbleSort(pSeqList pList);
int BinarySearch(pSeqList pList, DataType d);
void PrintfSeqList(pSeqList pList);
void Insert(pSeqList pList, int pos, DataType d);
void ReverseList(pSeqList pList);
void DestroySeqList(pSeqList pList);




#endif//__SEQLIST_H__ 


