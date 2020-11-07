#include "Stack.h"

//ջ�ĳ�ʼ��
void StackInit(Stack* ps) {
	assert(ps);//�ж�ps�Ƿ�Ϊ��
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}

//ջ������
void StackDestory(Stack* ps) {
	assert(ps);//����������psջ�ǿվ�û�б�Ҫ�ٽ���destory��
	free(ps->_array);//������ָ��ִ�е������ͷŵ�,��arrayָ��NULL
	ps->_array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}

//��ջ
void StackPush(Stack* ps, STDataType x) {//��Ϊ��һ����̬��ջ,��ִ�в�������Ǿ��б�Ҫ���������ж�
	assert(ps);
	if (ps->_capacity == ps->_top) {//ps��_top����_capacity����Ҫ��������
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_array = (STDataType*)realloc(ps->_array, sizeof(STDataType) * newcapacity);//λps->_arrayָ����������·���ռ�
		assert(ps->_array);//�ж�realloc�ͷ�ʧ��
		ps->_capacity = newcapacity;
	}
	ps->_array[ps->_top] = x;
	ps->_top++;//topֵ����
}

//��ջ
void StackPop(Stack* ps) {
	assert(ps && ps->_top > 0);//�ж��ͷ��ܶ�ps����pop����
	ps->_top--;
}

//����ջ��Ԫ��
STDataType StackTop(Stack* ps) {
	assert(ps && ps->_top > 0);
	return ps->_array[ps->_top - 1];
}

//���ջ�Ƿ�Ϊ��
int StackEmpty(Stack* ps) {
	assert(ps);
	return ps->_top == 0 ? 0 : 1;//0����stackΪ��,1����stack����Ԫ��
}

//����ջ�Ĵ�С
int StackSize(Stack* ps) {
	assert(ps);
	return ps->_top;
}

//��ӡջ������Ԫ��
void Stackprint(Stack* ps) {
	assert(ps);
	while (StackEmpty(ps) == 1) {//psջΪ�ǿ�
		printf("%d", StackTop(ps));
		StackPop(ps);
	}
	printf("\n");
}

//����ջ�ĺ���
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