#include<stdio.h>
#include<stdlib.h>


#define ElementType int//�궨���޶���
#define MAXSIZE 10
#define NULL -1
//���Ա�-->˳��洢�ṹ

typedef struct LineArr *List;//���嵽ǰ��
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


