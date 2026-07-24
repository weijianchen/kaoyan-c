#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 栈的基本运算：初始化、判空、进栈、退栈、取栈顶

// 链栈定义
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkStack;

void init(LinkStack *s);
bool is_empty(LinkStack s);
void push(LinkStack *s, int data);
bool pop(LinkStack *s, int *data);
bool get(LinkStack s, int *data);

int main(void)
{
    LinkStack s;
    printf("\nbefore init, the addres of stack is %p and the value of stack is %p ", (void *)&s, (void *)s);
    init(&s);
    printf("\nafter init, the addres of stack is %p and the value of stack is %p ", (void *)&s, (void *)s);
    printf("empty stack? : %d", is_empty(s));
    push(&s, 9);
    push(&s, 5);
    push(&s, 2);
    push(&s, 7);
    printf("\nafter push, the addres of stack is %p and the value of stack is %p and top is %d ", (void *)&s, (void *)s, s->data);
    int pop_data;
    pop(&s, &pop_data);
    int data;
    get(s, &data);
    printf("\nafter pop, the addres of stack is %p and the value of stack is %p and top is %d and the poped data is %d ", (void *)&s, (void *)s, s->data, pop_data);
}

// 初始化
void init(LinkStack *s)
{
    *s = NULL;
}

// 判空
bool is_empty(LinkStack s)
{
    return s == NULL;
}

// 进栈
void push(LinkStack *s, int data)
{
    LNode *p = (LNode*)malloc(sizeof(LNode));
    p->data = data;
    p->next = *s;
    *s = p;
}

// 退栈
bool pop(LinkStack *s, int *data)
{
    if(*s == NULL) return false;
    *data = (*s)->data;
    LNode *q = *s;
    *s = (*s)->next;
    free(q);
    return true;
}

// 取栈顶
bool get(LinkStack s, int *data)
{
    if(s == NULL) return false;
    *data = s->data;
    return true;
}
