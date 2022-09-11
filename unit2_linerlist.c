#include<stdio.h>
#include "datastruct.h"

int main(void){
    LinkList head = List_TailInsert(NULL);
    printf("Success!\n");
    printf("Long:%d\n",GetLong(head));
    InsertElemP(head,1,999);
    InsertElemB(head,1,9999);
    InsertElemB(head,GetLong(head),9999);
    LinkList head2 = SortUp(head);
    Display(head);
    Display(head2);
    return 0;



}