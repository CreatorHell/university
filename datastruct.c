#include "datastruct.h"
#include <stdlib.h>
LinkList List_HeadInsert(LinkList L){
    LNode *s;int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d",&x);
    while(x!=9999){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }

    return L;
}

LinkList List_TailInsert(LinkList L){
    LNode* s,*p;int x;
    p = L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d",&x);
    while (x!=9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;
        p->next = s;
        p = p->next;
        scanf("%d",&x);
    }
    return L;
    
}

LNode *GetElem(LinkList L, int i){
    LNode* p = L->next;
    int num = 1; // num = 1, because p : No.1
    // i = 0, return L
    if(i == 0){
        return L;
    }
    if(i < 1){
        return NULL;
    }


    while(num < i && p){
        p=p->next;
        num++;
    }
    return p;
}

LNode *LocateElem(LinkList L, int x){
    LNode* p = L->next;
    while(p != NULL && p->data != x)
        p = p->next;
    return p;
}

int GetLong(LinkList L){
    LNode *p = L->next;
    int num = 0;
    while (p)
    {
        p=p->next;
        num++;
    }
    return num;
}

LNode *InsertElemP(LinkList L, int i, int x){
    if(i < 1 || i > GetLong(L) + 1){
        printf("Invalid number.\n");
        return NULL;
    }else{
        LNode* s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;
        LNode *pre = GetElem(L, i - 1);
        s->next = pre->next;
        pre->next = s;
        return s;
    }
}

LNode *InsertElemB(LinkList L, int i, int x){
    if(i < 0 || i > GetLong(L)){
        printf("Invalid number.\n");
        return NULL;
    }else{
        LNode* s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;
        LNode *p = GetElem(L,i);
        if(i != GetLong(L)){
            s->next = p->next;
        }
        p->next = s;
        return s;
    }
}


int DelElem(LinkList L, int i){
    if(i < 0 || i > GetLong(L)){
        printf("Invalid number.\n");
        return NULL;
    }else{
        LNode *p = GetElem(L, i - 1);
        LNode *q = p->next;
        p->next = p->next->next;
        free(q);
    }
}

// delete *p : p.data = p.next.data;q = p.next;p.next= p.next.next;free(q);

void Display(LinkList L){
    LNode *p = L->next;
    int num = 0;
    while(p){
        num++;
        printf("%d:%d\n",num,p->data);
        p=p->next;
    }
}


LinkList SortUp(LinkList L){
    LinkList L2 = (LinkList)malloc(sizeof(LNode));
    L2->next = NULL;
    L2->data = -9999;
    LNode *p = L->next;
    while(p!= NULL){
        int num = 0;
        int data = p->data;
        LNode *pre = L2,*p2 = L2->next;
        while (p2!=NULL && p2->data < data)
        {
            num++;
            p2 = p2->next;
            pre = pre->next;
        }
        InsertElemB(L2,num,data);
        p = p->next;
    }
    return L2;
}

int SqInitStack(SqStack *S){
    S->top = -1;
    return 1; 
}

int SqStackEmpty(SqStack *S){
    return S->top != -1;
}

int SqPush(SqStack *S, int x){
    if(S->top < STACKMAXSIZE - 1){
        S->data[++S->top] = x;
        return 1;
    }else{
        return 0;
    }
}

int SqPop(SqStack *S, int *x){
    if(S->top > -1){
        *x = S->data[S->top--];
        return 1;
    }
    return 0;
}

int SqGetTop(SqStack *S, int *x){
    if(S->top > -1){
        *x = S->data[S->top];
        return 1;
    }
    return 0;
}

int SqDestoryStack(SqStack *S){
    S->top = -1;
    return 1;
}