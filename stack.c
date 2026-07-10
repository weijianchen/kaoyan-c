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
bool is_empty(SqStack *s)
{
    return s->top == -1;
}

// 进栈
bool push(SqStack *s, int data)
{
    if(s->top >= MAXSIZE -1) return false;
    s->data[++s->top] = data;
    return true;
}

// 退栈
bool pop(SqStack *s, int *data)
{
    if(is_empty(s)) return false;
    *data = s->data[s->top];
    s->top--;
    return true;
}

// 取栈顶
bool get_top(SqStack *s, int *data)
{
    if(is_empty(s)) return false;
    *data = s->data[s->top];
    return true;
}

// 链栈定义
typedef struct
{
    int data;
    LNode *next;
} LNode, *LinkStack;

// 初始化
void init_LinkStack(LinkStack *s)
{
    *s = (LinkStack)malloc(sizeof(LNode));
    
}

// 判空

// 进栈

// 退栈

// 取栈顶

int main()
{
    printf("hello stack!");
    return 0;
}