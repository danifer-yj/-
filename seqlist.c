#define _CRT_SECURE_NO_WARNINGS 1 

#include "seqlist.h" 

void InitSeqList(pSeqList pList)
{
    pList->sz = 0;
    pList->data = (DataType*)malloc(sizeof(DataType) * DEFAULT_SZ);
    if (pList->data == NULL)
    {
        perror("malloc");
        return;
    }
    memset(pList->data, 0, sizeof(DataType) * DEFAULT_SZ);
}
void CheckCapacity(pSeqList pList)
{
    assert(pList);
    if (pList->sz == pList->capacity)
    {
        DataType* ret = (DataType*)realloc(pList->data, sizeof(DataType) * (pList->capacity + INC_SZ));
        if (ret == NULL)
        {
            perror("realloc");
        }
        pList->data = ret;
        pList->capacity += INC_SZ;

    }
}
void PushBack(pSeqList pList, DataType d)
{
    assert(pList);
    if (pList->sz == pList->capacity)
    {
        CheckCapacity(pList);
    }
    pList->data[pList->sz] = d;
    pList->sz++;
}
void PopBack(pSeqList pList)
{
    int i = 0;
    assert(pList);
    if (pList->sz == 0)
    {
        printf("Ë³Ðò±íÎª¿Õ:<");
        return;
    }
    pList->sz--;
}
void PushFront(pSeqList pList, DataType d)
{
    int i = 0;
    assert(pList);
    if (pList->sz == pList->capacity)
    {
        CheckCapacity(pList);
    }
    for (i = pList->sz; i >= 1; i--)
    {
        pList->data[i] = pList->data[i - 1];
    }
    pList->data[0] = d;
    pList->sz++;
}
void PopFront(pSeqList pList)
{
    int i = 0;
    assert(pList);
    for (i = 0; i < pList->sz; i++)
    {
        pList->data[i] = pList->data[i + 1];
    }
    pList->sz--;
}
int Find(pSeqList pList, DataType d)
{
    int i = 0;
    assert(pList);
    while (i < pList->sz)
    {
        if (pList->data[i] == d)
        {
            return i;
        }
        else
        {
            i++;
        }
    }
    return -1;
}
void Remove(pSeqList pList, DataType d)
{
    int i = 0;
    int pos = 0;
    assert(pList);
    while (pList->data[pos = Find(pList, d)] == d)
    {
        for (i = pos; i < pList->sz - 1; i++)
        {
            pList->data[i] = pList->data[i + 1];
        }
        pList->sz--;
    }
}
void RemoveAll(pSeqList pList, DataType d)
{
    int i = 0;
    int pos = 0;
    assert(pList);
    while ((pos = Find(pList, d)) != -1)
    {
        for (i = pos; i < pList->sz - 1; i++)
        {
            pList->data[i] = pList->data[i + 1];
        }
        pList->sz--;
    }
}
void BubbleSort(pSeqList pList)
{
    int i = 0;
    assert(pList);
    for (i = 0; i < pList->sz - 1; i++)
    {
        int j = 0;
        for (j = 0; j < pList->sz - i - 1; j++)
        {
            if (pList->data[j] > pList->data[j + 1])
            {
                DataType tmp = pList->data[j];
                pList->data[j] = pList->data[j + 1];
                pList->data[j + 1] = tmp;
            }
        }
    }
}
int BinarySearch(pSeqList pList, DataType d)
{
    int left = 0;
    int right = pList->sz - 1;
    assert(pList);
    while (left <= right)
    {
        int mid = left - ((left - right) >> 1);
        if (d > pList->data[mid])
        {
            left = mid + 1;
        }
        else if (d < pList->data[mid])
        {
            right = mid - 1;
        }
        else
            return mid;
    }
    return -1;
}
void PrintfSeqList(pSeqList pList)
{
    int i = 0;
    for (i = 0; i < pList->sz; i++)
    {
        printf("%d ", pList->data[i]);
    }
}
void Insert(pSeqList pList, int pos, DataType d)
{
    int i = 0;
    if (pList->sz == pList->capacity)
    {
        CheckCapacity(pList);
    }
    for (i = pList->sz - 1; i >= pos; i--)
    {
        pList->data[i + 1] = pList->data[i];
    }
    pList->data[pos] = d;
    pList->sz++;
}
void ReverseList(pSeqList pList)
{
    int left = 0;
    int right = pList->sz - 1;
    assert(pList);
    while (left < right)
    {
        DataType tmp = pList->data[left];
        pList->data[left] = pList->data[right];
        pList->data[right] = tmp;
        left++;
        right--;
    }
}
void DestroySeqList(pSeqList pList)
{
    free(pList->data);
    pList->data = NULL;
}
