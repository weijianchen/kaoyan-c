#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 栈的基本运算：初始化、判空、进栈、退栈、取栈顶

// 顺序栈定义
#define MAXSIZE 10
typedef struct
{
    int data[MAXSIZE];
    int top;
} SqStack;

// 初始化
void init_SqStack(SqStack *s)
{
    s->top = -1;
}

// 判空
bool is_empty_sqstack(SqStack *s)
{
    return s->top == -1;
}

// 进栈
bool push_sqstack(SqStack *s, int data)
{
    if(s->top >= MAXSIZE -1) return false;
    s->data[++s->top] = data;
    return true;
}

// 退栈
bool pop_sqstack(SqStack *s, int *data)
{
    if(is_empty_sqstack(s)) return false;
    *data = s->data[s->top];
    s->top--;
    return true;
}

// 取栈顶
bool get_top_sqstack(SqStack *s, int *data)
{
    if(is_empty_sqstack(s)) return false;
    *data = s->data[s->top];
    return true;
}

int main(void)
{
    SqStack sq;
    printf("the default top is %d", sq.top);
    init_SqStack(&sq);
    printf("\nafter initial, the top is %d", sq.top);
    push_sqstack(&sq, 9);
    push_sqstack(&sq, 5);
    push_sqstack(&sq, 2);
    int data;
    get_top_sqstack(&sq, &data);
    printf("\nnow the top value is %d", data);
    int pop_data;
    pop_sqstack(&sq, &pop_data);
    printf("\nafter pop, now the top is %d and the top value is %d", sq.top, pop_data);
}
