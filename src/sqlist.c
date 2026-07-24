#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 顺序表定义
#define MAXSIZE 100
typedef struct
{
    int data[MAXSIZE];
    int length;
} SqList;

//函数声明
bool insert_sqlist(SqList *s, int data, int location);
bool delete_sqlist(SqList *s, int location, int *data);
int locate_sqlist(SqList *s, int data);

// 线性表基本操作：初始化、求表长、读表元、定位、插入、删除
int main(void)
{
    SqList sl = {{1, 9, 9, 4, 0, 1, 0, 7}, 8};
    printf("the length of sl is: %d\n", sl.length);
    printf("the third node of sl is %d\n", sl.data[2]);
    printf("4 is located at node %d\n", locate_sqlist(&sl, 4));
    if(insert_sqlist(&sl, 8, 3))
    {
        printf("after insert, the third node is %d and length is %d\n", sl.data[2], sl.length);
    }
    int data;
    if(delete_sqlist(&sl, 1, &data))
    {
        printf("after delete, the first node is %d and length is %d and the deleted data is %d\n", sl.data[0], sl.length, data);
    }
}

// 插入
bool insert_sqlist(SqList *l, int data, int location)
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
bool delete_sqlist(SqList *l, int location, int *data)
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
int locate_sqlist(SqList *l, int data)
{
    for (int i = 0; i < l->length - 1; i++)
    {
        if (l->data[i] == data)
            return i + 1;
    }
    
    return 0;
}
