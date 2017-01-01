#数据结构实验与实训教程（第四版）
###第一部分　预备知识
####[复数的基本运算](https://github.com/Anjaxs/DataStructure/blob/master/part1/complex.c)
1. 复数相加
2. 复数相减
3. 复数相乘
4. 复数相除
5. 复数求模

***

###第二部分　基础实验
####实验一　线性表的基本操作
1. [基础题](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment01/SqList.c)
    * 初始化线性表
    * 向线性表的指定位置插入元素
    * 删除指定元素值的线性表记录
    * 删除指定位置的线性表记录
    * 查找线性表中的元素
    * 输出线性表元素
2. 提升题
    * [将两个有序的线性表进行合并，要求同样的数据只出现一次](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment01/main2.c)  
    * [要求以较高的效率删除线性表中元素值在ｘ到ｙ（ｘ和ｙ自定）之间的所有元素](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment01/main3.c)    

***
####实验二　链表的基本操作
1. [基础题](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment02/LinkList.c)
    * 初始化链表
    * 向链表的指定位置插入元素
    * 向有序链表的指定位置插入元素
    * 删除指定元素值的链表记录
    * 查找链表中元素的位置
    * 释放链表空间
    * 输出链表
    
2. 提升题
    * [将一个头结点指针为ａ的单链表Ａ分解成两个单链表Ａ和Ｂ，其头结点指针分别为ａ和ｂ，使得Ａ链表含有原链表Ａ中序号为奇数的元素，Ｂ链表含有原链表Ａ中序号为偶数的元素，且保持原来的相对顺序。](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment02/main2.c)
    * [逆置链表。](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment02/main3.c)

***
####实验三　栈的基本操作
1. [基础题](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment03/Stack.c)
    * 进栈
    * 出栈
    * 输出栈
    
2. 提升题
    * [判断算术表达式中的括号是否匹配](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment03/main2.c)
    * [将中缀表达式转换成后缀表达式，并计算表达式的值](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment03/main3.c)

***
####实验四　队列的基本操作
1. 基础题
    * [链接队列](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment04/main1.c)
    * [环形队列](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment04/main2.c)
   
2. 提升题
    * [医务室模拟](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment04/main3.c)
    * [招聘模拟](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment04/main4.c)
    
***
####实验五　数组的基本操作
1. 基础题
    * [Fibonacci](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment05/main1.c)
    * [三角形](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment05/main2.c)
   
2. 提升题
    * [求两个多项式的最大公因式](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment05/main3.c)

***
####实验六　字符串的基本操作
1. 基础题
    * [简单模式匹配](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment06/main1.c)
    * [实现在两个已知字符串中找出最长公共子串，和最长公共子串的个数](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment06/main2.c)
    
2. 提升题
    * [kmp算法](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment06/main3.c)

***
####实验七　二叉树的基本操作
1. 基础题
    * [二叉排序树的基本操作函数](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment07/BSTree.c)
  
2. 提升题
    * [AVL树](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment07/avltree.c)

***
####实验八　树的遍历和哈弗曼树 
1. 基础题
    * [二叉树的递归遍历](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment08/main1.c)
    * [二叉树的非递归遍历](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment08/main2.c)
    
2. 提升题
    * [Huffman编码](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment08/HuffmanCodes.c)

***
####实验九　图的基本操作
1. [图的邻接矩阵](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment09/MGraph.c)
    
2. [图的邻接表](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment09/LGraph.c)
    
    
***
####实验十　排序
1. [基础题](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment10/main1.c)
    * 简单选择排序（选择排序）
    * 直接插入排序（插入排序）
    * 冒泡排序（交换排序）
    * 归并排序
    
2. [提升题](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment10/main2.c)
    * 堆排序（选择排序）
    * 希尔排序（插入排序）
    * 快速排序（交换排序）
    * [基数排序](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment10/RadixSort.c) 

***

####实验十一　查找
1. [基础题](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment11/main1.c)
    * 无序线性表的顺序查找
    * 有序线性表的顺序查找
    * 二分查找
    
2. 提升题
    * [采用随机函数产生职工的工号和他所完成产品个数的数据信息，然后按完成的数量对多名职工排序，数量一样的排在同一名次，且要显示同一名次的职工数量和职工号](https://github.com/Anjaxs/DataStructure/blob/master/part2/experiment11/main2.c)
    

***

### 第三部分　课程设计实验
#### [最小生成树的Kruskal算法](https://github.com/Anjaxs/DataStructure/blob/master/part3/Kruskal.c)


***
> .o文件是目标文件，是不常改变的，已经翻译成机器语言的文件，用于快速链接生产可执行文件。
> makefile文件包含编译命令的文件，使用make命令快速编译。




