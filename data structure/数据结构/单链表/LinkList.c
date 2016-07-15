#include <stdio.h>
#include <malloc.h>
#include "LinkList.h"

typedef struct _tag_LinkList
{
    LinkListNode header;
    int length;
}TLinkList;

LinkList* LinkList_Create()
{
    TLinkList* ret = (TLinkList*)malloc(sizeof(TLinkList));

    if(ret != NULL)
    {
        ret->length = 0;
        ret->header.next = NULL;
    }

    return ret;
}

void LinkList_Destroy(LinkList* list)
{
    free(list);
}

void LinkList_Clear(LinkList* list)
{
    TLinkList* sList = (TLinkList*)list;

    if(sList!=NULL)
    {
        sList->header.next = NULL;
        sList->length = 0;
    }
}

void LinkList_Reverse(LinkList* list)
{
    TLinkList* sList = (TLinkList*)list;

    if((sList!=NULL)&&(sList->length>1))
    {
        LinkListNode* current = (LinkListNode*)sList;
        LinkListNode* p = current->next;
        LinkListNode* q = current->next;

        q = q->next;
        p->next = NULL;
        p = q;

        while(p != NULL)
        {
            q = q->next;
            p->next = current->next;
            current->next = p;
            p = q;
        }
    }
}

int LinkList_Length(LinkList* list)
{
    TLinkList* sList = (TLinkList*)list;

    int ret = -1;

    if(sList!=NULL)
    {
        ret = sList->length;
    }

    return ret;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
    TLinkList* sList = (TLinkList*)list;

    int ret = (sList!=NULL) && (pos>=0) && (node!=NULL);

    int i = 0;

    if(ret)
    {
        if(pos >= sList->length)
        {
            pos = sList->length;
        }

        LinkListNode* current = (LinkListNode*)sList;

        for(i=0; (i<pos)&&(current->next!=NULL); i++)
        {
            current = current->next;
        }

        node->next = current->next;

        current->next = node;

        sList->length++;
    }

    return ret;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
    TLinkList* sList = (TLinkList*)list;

    LinkListNode* ret =NULL;

    int i = 0;

    if((sList!=NULL)&&(pos>=0) && (pos<sList->length))
    {
        LinkListNode* current = (LinkListNode*)sList;

        for(i=0; (i<pos)&&(current->next!=NULL); i++)
        {
            current = current->next;
        }

        ret = current->next;
    }

    return ret;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
    TLinkList* sList = (TLinkList*)list;

    LinkListNode* ret = NULL;

    int i = 0;

    if((sList!=NULL)&&(pos>=0)&&(pos<sList->length))
    {
        LinkListNode* current = (LinkListNode*)sList;

        for(i=0; i<pos; i++)
        {
            current = current->next;
        }

        ret = current->next;

        current->next = ret->next;

        sList->length--;
    }

    return ret;
}
