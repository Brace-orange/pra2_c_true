#include <stdio.h>

#define ElementType int//宏定义无逗号
#define MAXSIZE 10
#define NULL -1

//线性表-->顺序存储结构
typedef struct LineArr *List;//定义到前面
typedef struct LineArr
{
    ElementType Data[MAXSIZE];
    int last;
};


//初始化
List MakeEmptyLineArr()
{
    List Ptrl;
    Ptrl = (List)malloc(sizeof(struct LineArr));
    if (Ptrl != NULL)
    {
        Ptrl->last = -1;
        printf("Ptrl.last=%d\n", Ptrl->last);
        printf("functionM=%d\n", Ptrl);
    }
    else
    {
        printf("error memory\n");
    }

    return Ptrl;
}

//查找，普通查找,返回序号
ElementType Find(ElementType X, List Ptrl)
{
    int i = 0;
    while(i < Ptrl->last + 1 && Ptrl->Data[i] != X)
    {
        printf("xvnhuan\n");
        ++i;
        printf("i=%d", i);
        if (i > Ptrl->last)
     {
        printf("none\n");
        return -1;
     }
    if (Ptrl->Data[i] == X)
     {
        printf("have\n");
        return i;
     }
    }
}

//插入，给指定位置插入，返回数组的长度
int InsertElement (ElementType X, int i, List Ptrl)
{
    printf("ptrl->last%d\n", Ptrl->last);
    if (Ptrl->last == MAXSIZE - 1)
    {
        printf("表已满");
        return -1;
    }
    else if (i - 1 > MAXSIZE || i < 0)
    {
        printf("插入位置不合法");
        return -2;
    }
    else
    {
        int j = Ptrl->last - i -1;
        if (j < 0)
            {
                Ptrl -> Data[i - 1] = X;
                Ptrl -> last = i - 1;
                PrintArray(Ptrl -> Data, MAXSIZE);
            }
         else
         {
            for (j; j >= 0; j--)
          {
             Ptrl -> Data[i + j] = Ptrl -> Data[i + j -1];
             Ptrl -> last = i + j;
          }
          Ptrl -> Data[i -1] = X;
          PrintArray(Ptrl -> Data, MAXSIZE);
          printf("插入元素");
          }
        }

}

//打印数组
void PrintArray (ElementType arr[], int length)
{
    printf("printf arr\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("finish printf\n");

    return;
}

//删除指定位置数组，0 成功，-1 失败
int Delete (int i, List Ptrl)
{
    if (i < 0 || i > Ptrl -> last)
    {
        printf("the position is error\n");
        return -1;
    }
    else
    {
        for (int j = i-1; j <= Ptrl -> last; j++)
        {
            Ptrl -> Data[j] = Ptrl -> Data[j + 1];
        }
        Ptrl ->last--;
        PrintArray(Ptrl->Data, MAXSIZE);
        printf("delete finish");
        return 0;
    }
}

//（二）线性表--> 链式存储
typedef struct LineNode *ListNode;
struct LineNode {
   ElementType Data;
   ListNode Next;
};

//求表长
int LengthNode (ListNode PtrlNode)
{
    ListNode p = PtrlNode;//首地址
    int j = 0;
    while(p) {
        p = p -> Next;
        j++;
    }
    return j;
}

//查找，按序号查找，成功返回指针，-1-失败
ListNode FindKth(int K, ListNode PtrlNode)
{
    ListNode p = PtrlNode;
    int i = 1;
    while(p != NULL && i < K) {
        p = p -> Next;
        i++;
    }
    if(K ==i) {
        printf("finish to find the %dth elementery!", K);
        return p;//成功返回指针
    }
    else {
        printf("error find!");
        return NULL;
    }
}

//查找，按值查找
ListNode FindValue(ElementType K, ListNode PtrlNode)
{
    ListNode P = PtrlNode;
    while(P != NULL && P -> Data != K) {
        P = P -> Next;
    }
    return P;
}

//插入，返回首地址
ListNode InsertElementNode(ElementType K, int i,ListNode PtrlNode)
{
    ListNode p, s;
    if(i == 1) {
        s=(ListNode)malloc(sizeof(struct LineNode));
        s -> Data = K;
        s -> Next = PtrlNode;
        return s;
    }
    else {
        p = FindKth(i - 1, PtrlNode);
        if (p == NULL) {
            printf("error insert!");
            return NULL;
        } else {
            s = (ListNode)malloc(sizeof(ListNode));
            s -> Data = K;
            s -> Next = p -> Next;
            p -> Next = s;
            return p;
        }
    }
}

//删除，根据位置
int DeleteNode(int i, ListNode PtrlNode)
{
    ListNode p;
    p = FindKth(i - 1, PtrlNode);
    if (p == NULL) {
        printf("error deleteNode!");
        return -1;
    } else {
        p -> Next = p -> Next -> Next;
        return 0;
    }
}

//（三）堆栈,
#define MAXSIZESNODE 20
typedef struct SNode *Stack;
struct SNode {
   ElementType Data[MAXSIZESNODE];
   int Top;
};

//入栈,one Stack
void Push(ElementType item, Stack PtrlSNode) {
    if (MAXSIZESNODE - 1 == PtrlSNode -> Top) {
        printf("full of Stack");
        return -1;
    } else {
        PtrlSNode -> Data[++(PtrlSNode -> Top)];
        return 0;
    }
}

//出栈，one Stack
ElementType Pop(Stack PtrlSNode) {
    if (PtrlSNode -> Top == -1) {
        printf("nothing in this stack");
        return;
    } else {
        return PtrlSNode -> Data[(PtrlSNode -> Top)--];
    }
}

//two Stack,two sides
#define MAXSIZEDSNODE 20
typedef struct DSNode *DStack;
struct DSNode {
    ElementType Data[MAXSIZEDSNODE];
    int TopStart;
    int TopEnd;
};


