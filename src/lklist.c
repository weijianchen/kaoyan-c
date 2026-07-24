#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 线性表基本操作：初始化、求表长、读表元、定位、插入、删除
// 单链表定义
#define MAXSIZE 100
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkedList;

LinkedList tail_build_no_head(void);
LinkedList head_build(void);
LinkedList tail_build(void);
int calculate_length_with_head(LinkedList l);
LNode *find_by_location(LinkedList l, int location);
int find_by_value(LinkedList l, int data);
bool insert_with_head(LinkedList l, int data, int location);
bool delete(LinkedList l, int location, int *data);
void get_linklist(LinkedList l);
bool initial_with_head(LinkedList *l);

int main(void)
{
    LinkedList l1 = tail_build_no_head();
    printf("the LinkList created with 尾插法 is:\n");
    get_linklist(l1);
    printf("\n----------\n");

    LinkedList l2 = head_build();
    printf("the LinkList created with 带头结点的头插法 is:\n");
    get_linklist(l2);
    printf("\n----------\n");

    LinkedList l3 = tail_build();
    printf("the LinkList created with 带头结点的尾插法 is:\n");
    get_linklist(l3);
    printf("\nand the length is %d ", calculate_length_with_head(l3));
    printf("\nand the second node is %d ", find_by_location(l3, 2)->data);
    printf("\nand the location of 2 is %d ", find_by_value(l3, 2));
    insert_with_head(l3, 007, 1);
    printf("\nafter insert 007 in node 1, the new LinkList is:\n");
    get_linklist(l3);
    int data;
    delete(l3, 2, &data);
    printf("\nafter delete node 2, the new LinkList is:\n");
    get_linklist(l3);
    printf("\nand the delete node value is %d ", data);
    printf("\n----------\n");

    printf("the address of l3 is %p and the value of l3 is %p", (void *)&l3, (void *)l3);
    initial_with_head(&l3);
    printf("\nafter initial, the address of l3 is %p and the value of l3 is %p", (void *)&l3, (void *)l3);
    printf("\nand the new LinkList is:\n");
    get_linklist(l3);
    printf("\n----------\n");
}

//尾插法建表
LinkedList tail_build_no_head(void)
{
    int x;
    LNode *s, *r;
    LinkedList l = NULL;
    r = l;
    scanf("%d", &x);
    while(x != 999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        if(l == NULL)
        {
            l = s;
            r = s;
        }
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return l;
}

// 带头结点的头插法建表
LinkedList head_build(void)
{
    int x;
    LNode *s;
    LinkedList l = (LinkedList)malloc(sizeof(LNode));
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
LinkedList tail_build(void)
{
    int x;
    LinkedList l = (LinkedList)malloc(sizeof(LNode));
    LNode *r = l, *s;
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
bool initial_with_head(LinkedList *l)
{
    *l = (LinkedList)malloc(sizeof(LNode));
    if(*l == NULL)
    return false;
    (*l)->next = NULL;
    return true;
}

// 求表长
int calculate_length_with_head(LinkedList l)
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

// 按序号查找,0则返回头结点
LNode *find_by_location(LinkedList l, int location)
{
    if (location < 0) return NULL;
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
bool insert_with_head(LinkedList l, int data, int location)
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
bool delete(LinkedList l, int location, int *data)
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

void get_linklist(LinkedList l)
{
    if(l == NULL)
    printf("\nit is an empty list");
    else
    {
        while(l != NULL)
        {
            printf("%d ", l->data);
            l = l->next;
        }
    }
}

// 静态链表定义
typedef struct
{
    int data;
    int next;
} StaticList[MAXSIZE];

// 初始化
