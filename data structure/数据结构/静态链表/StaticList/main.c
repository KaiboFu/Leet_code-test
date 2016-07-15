#include <stdio.h>
#include <stdlib.h>
#include "StaticList.h"

int main(void)
{
    StaticList* list = StaticList_Create(10);

    int index = 0;

    int i=0, j=1, k=2, x=3, y=4, z=5;

    StaticList_Insert(list, &i, 0);
    StaticList_Insert(list, &j, 0);
    StaticList_Insert(list, &k, 0);

    for(index=0; index<StaticList_Length(list); index++)
    {
        int* p = (int*)StaticList_Get(list, index);

        printf("%d\n", *p);
    }
    printf("\n");

    while(StaticList_Length(list) > 0)
    {
        int* p = (int*)StaticList_Delete(list, StaticList_Length(list)-1);

        printf("%d\n", *p);
    }

    StaticList_Insert(list, &x, 0);
    StaticList_Insert(list, &y, 0);
    StaticList_Insert(list, &z, 0);

    printf("Capacity:%d Length:%d\n", StaticList_Capacity(list), StaticList_Length(list));
    printf("\n");

    for(index=0; index<StaticList_Length(list); index++)
    {
        int* p = (int*)StaticList_Get(list, index);

        printf("%d\n", *p);
    }

    StaticList_Destroy(list);

    return 0;
}
