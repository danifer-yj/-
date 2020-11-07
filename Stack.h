#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include <assert.h>

/* �����Ƕ����ľ�̬ջ�Ľṹ��ʵ����һ�㲻ʵ�ã�����������Ҫʵ�������֧�ֶ�̬������ջ
#define N 10
typedef int STDataType;
typedef struct Stack
{
	STDataType _a[N];
	int _top; // ջ��
}Stack;
*/
// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* _array;//������ݵ�����
	int _top; // ջ��
	int _capacity; // ����
}Stack;

//ջ�ĳ�ʼ��
void StackInit(Stack* ps);
//ջ������
void StackDestory(Stack* ps);

//��ջ
void StackPush(Stack* ps, STDataType x);
//��ջ
void StackPop(Stack* ps);
//����ջ��Ԫ��
STDataType StackTop(Stack* ps);

//���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps);
//����ջ�Ĵ�С
int StackSize(Stack* ps);

//��ӡջ������Ԫ��
void Stackprint(Stack* ps);

//����ջ�ĺ���
void TestStack();

#endif/*__STACK_H__*/