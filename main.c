#include <stdio.h>
#include <stdlib.h>
#include "function.h"


int main()
{
    //LineArrOperation();
    return 0;
}

void LineArrOperation ()
{
    printf("Hello world!\n");
    List Ptrl;
    Ptrl = MakeEmptyLineArr();
    printf("main=%d\n", Ptrl);
    int i=0;
    for(i; i < MAXSIZE - 2; i++){
         Ptrl->Data[i] = i;
         Ptrl->last = i;
    }
    ElementType j = Find(90, Ptrl);
    printf("findi=%d\n", j);
    InsertElement(300, 10, Ptrl);
    Delete(4, Ptrl->Data);
}
