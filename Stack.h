#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include <assert.h>

/* 下面是定长的静态栈的结构，实际中一般不实用，所以我们主要实现下面的支持动态增长的栈
#define N 10
typedef int STDataType;
typedef struct Stack
{
	STDataType _a[N];
	int _top; // 栈顶
}Stack;
*/
// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _array;//存放数据的数组
	int _top; // 栈顶
	int _capacity; // 容量
}Stack;

//栈的初始化
void StackInit(Stack* ps);
//栈的销毁
void StackDestory(Stack* ps);

//入栈
void StackPush(Stack* ps, STDataType x);
//出栈
void StackPop(Stack* ps);
//返回栈顶元素
STDataType StackTop(Stack* ps);

//检查栈是否为空
int StackEmpty(Stack* ps);
//返回栈的大小
int StackSize(Stack* ps);

//打印栈的所有元素
void Stackprint(Stack* ps);

//测试栈的函数
void TestStack();

#endif/*__STACK_H__*/