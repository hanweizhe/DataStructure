#ifndef _STACK_H_
#define _STACK_H_ 

#include <stdbool.h>
#define MAXN 10

typedef int ElemType; /* 定义栈的类型为int */
typedef struct{
   ElemType data[MAXN];
   int top;
}SqStack;


/**
 * 初始化栈
 * @param s [description]
 */
void InitStack (SqStack * s);


/**
 * 判断栈是否满了
 * @param  s 
 * @return   boolean
 */
bool IsFull( SqStack * s );


/**
 * 判断栈是否为空
 * @param  s 
 * @return   boolean
 */
bool IsEmpty( SqStack * s );


/**
 * 若栈没满，插入新元素e到栈顶，成功返回true，否则返回false。
 * @param  s 
 * @param  e 待插入元素
 * @return   boolean
 */
bool Push (SqStack * s, ElemType e);    


/**
 * 若栈非空，删除栈顶元素，并用e返回栈顶元素。
 * @param  s 
 * @param  e 
 * @return   boolean
 */
bool Pop (SqStack * s, ElemType *e);


/**
 * 输出栈
 * @param s 
 */
void OutPutStack (SqStack * s);



#endif