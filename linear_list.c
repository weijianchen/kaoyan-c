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
bool delete(SqList *l, int location, int *data)
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

// 带头结点的尾插法建表

// 带头结点的头插法建表

// 初始化

// 求表长

// 按序号查找

// 定位

// 插入

// 删除

// 静态链表定义

// 初始化

int main()
{
    printf("hello world!");
    return 0;
}