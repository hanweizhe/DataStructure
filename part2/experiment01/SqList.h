#ifndef _SQLIST_H_
#define _SQLIST_H_

/**
 * 定义线性表结构
 */
struct LinearList		
{
	int * list;			//存线性表元素
	int size;			//存线性表长度
	int MaxSize;		//存ｌｉｓｔ数组元素的个数
};
typedef struct LinearList List;


/**
 * 初始化线性表	
 * @param L       
 * @param ms    定义线性表最大长度  
 */
void InitList (List * L, int ms);


/**
 * 插入操作
 * @param  L    
 * @param  item 记录值
 * @param  rc   插入位置
 * @return      0:success, -1:false
 */
int InsertList (List * L, int item, int rc);


/**
 * 输出操作
 * @param L 
 */
void OutputList (List * L);


/**
 * 查找第一个符合元素的位置
 * @param  L    
 * @param  item 待查找元素
 * @return      >=0:元素位置,　-1:没找到
 */
int FindList (List * L, int item);


/**
 * 删除指定元素值的线性表记录，返回值>0为删除成功
 * @param  L    
 * @param  item 
 * @return  删除个数    
 */
int DeleteList1 (List * L, int item);


/**
 * 删除指定位置的线性表记录 返回值>=0为删除成功
 * @param  L    
 * @param  rc   
 * @return      
 */
int DeleteList2 (List * L, int rc);

#endif