#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 线性表基本操作：初始化、求表长、读表元、定位、插入、删除

// 顺序表定义
#define MAXSIZE 100
typedef struct
{
    int data[MAXSIZE];
    int length;
} SqList;

// 插入
bool insert(SqList *l, int data, int location)
{
    if (location < 1 || location > l->length)
        return false;

    if (l->length >= MAXSIZE)
        return false;

    for (int i = l->length; i >= location; i--)
        l->data[i] = l->data[i - 1];

    l->data[location - 1] = data;
    l->length++;
    return true;
}

// 删除
bool delete_spot(SqList *l, int location, int *data)
{
    if (location < 1 || location > l->length)
        return false;

    *data = l->data[location - 1];
    for (int i = location - 1; i < l->length; i++)
        l->data[i] = l->data[i + 1];
    l->length--;
    return true;
}

// 定位
int locate(SqList *l, int data)
{
    for (int i = 0; i < l->length - 1; i++)
    {
        if (l->data[i] == data)
            return i + 1;
    }
    
    return 0;
}

// 单链表定义
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkedList;

// 带头结点的头插法建表
LinkedList head_build(LinkedList l)
{
    int x;
    LNode *s;
    l = (LinkedList)malloc(sizeof(LNode));
    l->next = NULL;
    scanf("%d", &x);
    while(x != 999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = l->next;
        l->next = s;
        scanf("%d", &x);
    }
    return l;
}

// 带头结点的尾插法建表
LinkedList tail_build(LinkedList l)
{
    int x;
    LNode *r = l, *s;
    l = (LinkedList)malloc(sizeof(LNode));
    l->next = NULL;
    scanf("%d", &x);
    while(x != 999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    s->next = NULL;
    return l;
}

// 初始化
LinkedList *initial()
{
    LNode *l = (LinkedList)malloc(sizeof(LNode));
    return l;
}

// 求表长
int calculate_length(LinkedList l)
{
    int i = 0;
    LNode *p = l->next;
    while(p != NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}

// 按序号查找
LNode *find_by_location(LinkedList l, int location)
{
    if (location < 1) return NULL;
    int i = 0;
    LNode *p = l;
    while(p != NULL && i < location)
    {
        p = p->next;
        i++;
    }
    return p;
}

// 定位
int find_by_value(LinkedList l, int data)
{
    int i = 0;
    LNode *p = l;
    while(p != NULL && p->data != data)
    {
        p = p->next;
        i++;
    }
    if(p == NULL) return 0;
    else return i;
}

// 插入
bool insert(LinkedList l, int data, int location)
{
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = data;
    LNode *p = find_by_location(l, location - 1);
    if(p == NULL) return false;
    else
    {
        s->next = p->next;
        p->next = s;
        return true;
    }
}

// 删除
bool delete_s(LinkedList l, int location, int *data)
{
    LNode *p = find_by_location(l, location - 1);
    if(p == NULL || p->next == NULL) return false;
    else
    {
        LNode *q = p->next;
        *data = q->data;
        p->next = p->next->next;
        free(q);
        return true;
    }
}

// 静态链表定义
typedef struct
{
    int data;
    int next;
} StaticList[MAXSIZE];

// 初始化


int main()
{
    printf("hello world!");
    return 0;
}