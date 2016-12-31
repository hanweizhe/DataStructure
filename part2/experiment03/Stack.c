#include <stdio.h>
#include "Stack.h"

void InitStack( SqStack * s )
{
   s->top = -1;
}

bool IsFull( SqStack * s )
{
   return s->top == MAXN-1?true:false;
}

bool IsEmpty( SqStack * s )
{
   return s->top == -1?true:false;
}

void OutPutStack(SqStack * s) //输出栈
{
   int i;
   int len = s->top + 1;
   printf("\t--top--\n");
   for (i = MAXN-1; i >= 0; i-- ) {
      /*如果栈里的空间没有值*/
      if ( i >= len ) {
         printf("\t|    |\n\t ---- \n");
      } else {
         printf("\t| %2d |\n\t ---- \n", s->data[i]);
      }
   }
   printf("\n");
}

bool Push( SqStack *s, ElemType e )
{
   if ( IsFull( s ) )
      return false;
   s->data[++s->top] = e;
   return true;
}

bool Pop( SqStack * s, ElemType *e )
{
   if ( IsEmpty(s) )
      return false;
   *e = s->data[s->top--];
   return true;
}



