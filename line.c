#include<stdio.h>
#include<stdlib.h>


#define ElementType int//宏定义无逗号
#define MAXSIZE 10
#define NULL -1
//线性表-->顺序存储结构

typedef struct LineArr *List;//定义到前面
typedef struct LineArr
{
    ElementType data[MAXSIZE];
    int last;
};



List MakeEmptyLineArr()
{
    List Ptrl;
    Ptrl = (List)malloc(sizeof(struct LineArr));
    if (Ptrl != NULL)
    {
        printf("b");
        Ptrl->last = -1;
    }
    else
    {
        printf("a");
    }

    return Ptrl;
}


