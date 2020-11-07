//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <assert.h>
//#include <stddef.h>
//
//typedef int SLDataType;
//
//// ˳���Ķ�̬�洢
//typedef struct SeqList
//{
//    SLDataType* array; // ָ��̬���ٵ�����
//    int size; // ��Ч���ݸ���
//    int capacity; // �����ռ�Ĵ�С
//}SeqList;
//// ������ɾ��Ľӿ�
//void SeqListInit(SeqList* psl, int capacity) {
//    SeqList* myList = (SeqList*)malloc(sizeof(SeqList));//�����ڴ�
//    //��ʼ��
//    myList->size = 0;
//    myList->capacity = capacity;
//    myList->array = (SLDataType*)malloc(sizeof(SLDataType) * myList->capacity);
//}
//
//void SeqListDestory(SeqList* psl) {      //���ٶ�̬������ڴ�
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
//        //��һ������һ�������µĿռ�
//        SLDataType* newSpace = (SLDataType*)malloc(sizeof(SLDataType)*psl->capacity*2);
//        //�ڶ���: �������ݵ��¿ռ���
//        memcpy(newSpace,psl->array,psl->capacity*sizeof(SLDataType));
//        //������: �ͷžɵĿռ�
//        free(psl->array);
//        //��������
//        psl->capacity = psl->capacity*2;
//        psl->array = newSpace;
//    }
//    //��Ԫ�ز���
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
//        printf("˳���Ϊ��");
//        return;
//    }
//    psl->size--;
//}
//
//void SeqListPushFront(SeqList* psl, SLDataType x) {
//    int i = 0;
//    assert(psl);
//    if (psl->size == psl->capacity) {
//        CheckCapacity(psl);     //����
//    }
//    for (i = psl->size; i >= 1; i--) {//sizeλ���ϵ�Ԫ��Ϊ��
//        psl->array[i] = psl->array[i - 1];
//    }
//    psl->array[0] = x;
//    psl->size++;
//}
//void SeqListPopFront(SeqList* psl) {
//    int i = 0;
//    assert(psl);
//    for (i = 0; i < psl->size; i++) {
//        psl->array[i] = psl->array[i + 1];    //�ӵ�һ��Ԫ�ؿ�ʼ,����һ��Ԫ�ظ�ֵ��ǰһ��Ԫ��
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
//    //��pos����λ�õ�Ԫ������ƶ�һλ,�������ڳ���pos��λ��
//    for (i = psl->size - 1; i >= pos; --i) {
//        psl->array[i + 1] = psl->array[i];//����i��Ԫ�ظ���i+1��Ԫ��
//    }
//    psl->array[pos] = x;
//    psl->size++;
//}
//
//void SeqListErase(SeqList* psl, int pos) {
//    //��pos֮���Ԫ��������ǰ����
//    assert(psl);
//    int i = 0;
//    for (i = pos; i < psl->size; ++i) {
//        psl->array[i] = psl->array[i + 1];
//    }
//    psl->size--;
//}
//
//void SeqListRemove(SeqList* psl, SLDataType x) {
//    int pos = 0;//��¼x��array�е�λ��
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
//// ��չ������ʵ��
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
//// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
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