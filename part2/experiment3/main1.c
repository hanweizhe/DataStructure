#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Stack.h"

int main()
{
   int i;
   ElemType e;
   SqStack s;
   InitStack( &s );
   /*生成随机数,*/
   srand((unsigned)time(NULL));
   for ( i = 0 ; i < MAXN ; i++ ) {
      e = rand()%100;
      Push( &s, e );
      printf("Push %d\n", e);
      OutPutStack( &s );
   }
   e = s.data[s.top];
   printf("top : %d\n", e);

   OutPutStack( &s );

   /*删除元素*/
   printf("after pop (s) \n");
   Pop(&s , &e);
   OutPutStack( &s );

   return 0;
}

