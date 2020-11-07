//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <assert.h>
//#include <stddef.h>
//
//typedef int SLDataType;
//
//// 顺序表的动态存储
//typedef struct SeqList
//{
//    SLDataType* array; // 指向动态开辟的数组
//    int size; // 有效数据个数
//    int capacity; // 容量空间的大小
//}SeqList;
//// 基本增删查改接口
//void SeqListInit(SeqList* psl, int capacity) {
//    SeqList* myList = (SeqList*)malloc(sizeof(SeqList));//申请内存
//    //初始化
//    myList->size = 0;
//    myList->capacity = capacity;
//    myList->array = (SLDataType*)malloc(sizeof(SLDataType) * myList->capacity);
//}
//
//void SeqListDestory(SeqList* psl) {      //销毁动态数组的内存
//    /*if(psl == NULL){
//        return ;
//    }
//    if(psl->array != NULL){
//        free(psl->array);
//    }
//    free(psl);
//    */
//    free(psl->array);
//    psl->array = NULL;
//}
//void CheckCapacity(SeqList* psl) {
//    /*if(psl->size == psl->capacity){
//        return true;;
//    }
//    else{
//        return false;
//    }*/
//    assert(psl);
//    if (psl->size == psl->capacity) {
//        SLDataType* ret = (SLDataType*)realloc(psl->array, sizeof(SLDataType) * (psl->capacity * 2));
//        if (ret == NULL) {
//            perror("realloc");
//        }
//        psl->array = ret;
//        psl->capacity *= 2;
//    }
//}
//
//void SeqListPushBack(SeqList* psl, SLDataType x) {
//    /*if(psl == NULL){
//        return ;
//    }
//    if(CheckCapacity(psl) == true){
//        //第一步申请一块更大的新的空间
//        SLDataType* newSpace = (SLDataType*)malloc(sizeof(SLDataType)*psl->capacity*2);
//        //第二部: 拷贝数据到新空间中
//        memcpy(newSpace,psl->array,psl->capacity*sizeof(SLDataType));
//        //第三部: 释放旧的空间
//        free(psl->array);
//        //跟新容量
//        psl->capacity = psl->capacity*2;
//        psl->array = newSpace;
//    }
//    //将元素插入
//    psl->array[(psl->size)] = x;
//    psl->size++;
//    */
//    assert(psl);
//    if (psl->size == psl->capacity) {
//        CheckCapacity(psl);
//    }
//    psl->array[psl->size-1] = x;
//    psl->size++;
//}
//
//void SeqListPopBack(SeqList* psl) {
//    /*if(psl == NULL){
//        return ;
//    }
//    free(psl);
//    */
//    assert(psl);
//    if (psl->size == 0) {
//        printf("顺序表为空");
//        return;
//    }
//    psl->size--;
//}
//
//void SeqListPushFront(SeqList* psl, SLDataType x) {
//    int i = 0;
//    assert(psl);
//    if (psl->size == psl->capacity) {
//        CheckCapacity(psl);     //扩容
//    }
//    for (i = psl->size; i >= 1; i--) {//size位置上的元素为空
//        psl->array[i] = psl->array[i - 1];
//    }
//    psl->array[0] = x;
//    psl->size++;
//}
//void SeqListPopFront(SeqList* psl) {
//    int i = 0;
//    assert(psl);
//    for (i = 0; i < psl->size; i++) {
//        psl->array[i] = psl->array[i + 1];    //从第一个元素开始,将后一个元素赋值给前一个元素
//        psl->size--;
//    }
//}
//
//int SeqListFind(SeqList* psl, SLDataType x) {
//    if (psl == NULL) {
//        return -1;
//    }
//    int pos = -1;
//    for (int i = 0; i < psl->size; ++i) {
//        if (psl->array[i] == x) {
//            pos = i;
//            break;
//        }
//    }
//    return pos;
//}
//
//void SeqListInsert(SeqList* psl, int pos, SLDataType x) {
//    int i = 0;
//    if (psl->size == psl->capacity) {
//        CheckCapacity(psl);
//    }
//    //将pos后面位置的元素向后移动一位,这样就腾出了pos的位置
//    for (i = psl->size - 1; i >= pos; --i) {
//        psl->array[i + 1] = psl->array[i];//将第i个元素赋给i+1个元素
//    }
//    psl->array[pos] = x;
//    psl->size++;
//}
//
//void SeqListErase(SeqList* psl, int pos) {
//    //将pos之后的元素依次向前覆盖
//    assert(psl);
//    int i = 0;
//    for (i = pos; i < psl->size; ++i) {
//        psl->array[i] = psl->array[i + 1];
//    }
//    psl->size--;
//}
//
//void SeqListRemove(SeqList* psl, SLDataType x) {
//    int pos = 0;//记录x在array中的位置
//    int i = 0;
//    assert(psl);
//    while ((pos = SeqListFind(psl, x)) != -1) {
//        for (i = pos; i < psl->size; ++i) {
//            psl->array[i] = psl->array[i + 1];
//        }
//        psl->size--;
//    }
//}
//
//void SeqListModify(SeqList* psl, int pos, SLDataType x) {
//    if (psl == NULL) {
//        return;
//    }
//    psl->array[pos] = x;
//}
//
//void SeqListPrint(SeqList* psl) {
//    if (psl == NULL) {
//        return;
//    }
//    for (int i = 0; i < psl->size; ++i) {
//        printf("%d", psl->array[i]);
//    }
//    printf("\n");
//}
//
//// 扩展面试题实现
//void SeqListBubbleSort(SeqList* psl);
//
//int SeqListBinaryFind(SeqList* psl, SLDataType x) {
//    int left = 0;
//    int right = psl->size - 1;
//    assert(psl);
//    while (left <= right) {
//        int mid = left + ((right - left) >> 1);
//        if (x > psl->array[mid]) {
//            left = mid + 1;
//        }
//        else if (x < psl->array[mid]) {
//            right = mid - 1;
//        }
//        else
//        {
//            return mid;
//        }
//    }
//    return -1;
//}
//
//// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
//void SeqListRemoveAll(SeqList* psl, SLDataType x);
//
//void Test() {
//    SeqList* psl;
//    SeqListInit(&psl, 10);
//    SeqListPushBack(&psl, 1);
//    SeqListPushBack(&psl, 13);
//    SeqListPushBack(&psl, 10);
//    SeqListPushBack(&psl, 11);
//    SeqListPrint(&psl);
//}
//
//int main1() {
//
//    return 0;
//}