#include "Stack.h"

//栈的初始化
void StackInit(Stack* ps) {
	assert(ps);//判断ps是否为空
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}

//栈的销毁
void StackDestory(Stack* ps) {
	assert(ps);//若传进来的ps栈是空就没有必要再进行destory了
	free(ps->_array);//将数据指针执行的内容释放掉,将array指向NULL
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

//入栈
void StackPush(Stack* ps, STDataType x) {//因为是一个动态的栈,在执行插入操作是就有必要进行扩容判断
	assert(ps);
	if (ps->_capacity == ps->_top) {//ps的_top等于_capacity就需要进行扩容
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_array = (STDataType*)realloc(ps->_array, sizeof(STDataType) * newcapacity);//位ps->_array指向的内容重新分配空间
		assert(ps->_array);//判断realloc释放失败
		ps->_capacity = newcapacity;
	}
	ps->_array[ps->_top] = x;
	ps->_top++;//top值增加
}

//出栈
void StackPop(Stack* ps) {
	assert(ps && ps->_top > 0);//判断释放能对ps进行pop操作
	ps->_top--;
}

//返回栈顶元素
STDataType StackTop(Stack* ps) {
	assert(ps && ps->_top > 0);
	return ps->_array[ps->_top - 1];
}

//检查栈是否为空
int StackEmpty(Stack* ps) {
	assert(ps);
	return ps->_top == 0 ? 0 : 1;//0代表stack为空,1代表stack中有元素
}

//返回栈的大小
int StackSize(Stack* ps) {
	assert(ps);
	return ps->_top;
}

//打印栈的所有元素
void Stackprint(Stack* ps) {
	assert(ps);
	while (StackEmpty(ps) == 1) {//ps栈为非空
		printf("%d", StackTop(ps));
		StackPop(ps);
	}
	printf("\n");
}

//测试栈的函数
void TestStack() {
	Stack s;
	StackInit(&s);
	StackPush(&s, 2);
	StackPush(&s, 6);
	StackPush(&s, 8);
	StackPush(&s, 4);

	printf("%d\n", StackTop(&s));
	printf("%d\n", StackEmpty(&s));
	printf("%d\n", StackSize(&s));

	Stackprint(&s);
	StackDestory(&s);
}