#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

int main(void)
{
    SeqList* list = SeqList_Create(6);

    int i=0, j=1, k=2;
    int x=3, y=4, z=5;

    int index = 0;

    SeqList_Insert(list, &i, 0);
    SeqList_Insert(list, &j, 0);
    SeqList_Insert(list, &k, 0);
    SeqList_Insert(list, &x, 0);
    SeqList_Insert(list, &y, 0);
    SeqList_Insert(list, &z, 0);

    for(index=0; index<SeqList_Length(list); index++)
    {
        int* p = (int*)SeqList_Get(list, index);

        printf("%d\n", *p);
    }

    while(SeqList_Length(list) > 0)
    {
        int* p = (int*)SeqList_Delete(list, 0);

        printf("%d\n", *p);
    }

    SeqList_Destroy(list);

    return 0;
}
