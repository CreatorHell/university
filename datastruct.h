#ifndef DATASTRUCTH // datastruct
#define DATASTRUCTH

typedef struct LNode{
    int data;
    struct LNode* next;
}LNode, *LinkList;

LinkList List_HeadInsert(LinkList L);

LinkList List_TailInsert(LinkList L);

LNode *GetElem(LinkList L, int i);

LNode *LocateElem(LinkList L, int x);

int GetLong(LinkList L);

LNode *InsertElemP(LinkList L, int i, int x);

LNode *InsertElemB(LinkList L, int i, int x);


int DelElem(LinkList L, int i);

void Display(LinkList L);

LinkList SortUp(LinkList);

#define STACKMAXSIZE 50

typedef struct SqStack{
    int data[STACKMAXSIZE];
    int top;
} SqStack;

int SqInitStack(SqStack *S); 

int SqStackEmpty(SqStack *S);

int SqPush(SqStack *S, int x);
int SqPop(SqStack *S, int *x);

int SqGetTop(SqStack *S, int *x);

int SqDestoryStack(SqStack *S);

#endif