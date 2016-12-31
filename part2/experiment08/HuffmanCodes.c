/**
 * 
In 1953, David A. Huffman published his paper "A Method for the Construction of
Minimum-Redundancy Codes", and hence printed his name in the history of computer science. As a
professor who gives the final exam problem on Huffman codes, I am encountering a big problem: 
the Huffman codes are NOT unique. For example, given a string "aaaxuaxz", we can observe that 
the frequencies of the characters 'a', 'x', 'u' and 'z' are 4, 2, 1 and 1, respectively. We may
either encode the symbols as {'a'=0, 'x'=10, 'u'=110, 'z'=111}, or in another way as {'a'=1,
'x'=01, 'u'=001, 'z'=000}, both compress the string into 14 bits. Another set of code can be
given as {'a'=0, 'x'=11, 'u'=100, 'z'=101}, but {'a'=0, 'x'=01, 'u'=011, 'z'=001} is NOT
correct since "aaaxuaxz" and "aazuaxax" can both be decoded from the code 00001011001001. The
students are submitting all kinds of codes, and I need a computer program to help me determine
which ones are correct and which ones are not.

Input Specification:

Each input file contains one test case. For each case, the first line gives an integer N (2 <= N
 <= 63), then followed by a line that contains all the N distinct characters and their 
 frequencies in the following format:

c[1] f[1] c[2] f[2] ... c[N] f[N]

where c[i] is a character chosen from {'0' - '9', 'a' - 'z', 'A' - 'Z', '_'}, and f[i] is the
frequency of c[i] and is an integer no more than 1000. The next line gives a positive integer M
(<=1000), then followed by M student submissions. Each student submission consists of N lines,
each in the format:

c[i] code[i]

where c[i] is the i-th character and code[i] is a string of '0's and '1's.

Output Specification:

For each test case, print in each line either “Yes” if the student’s submission is correct, or
“No” if not.

Sample Input:

7
A 1 B 1 C 1 D 3 E 3 F 6 G 6
4
A 00000
B 00001
C 0001
D 001
E 01
F 10
G 11
A 01010
B 01011
C 0100
D 011
E 10
F 11
G 00
A 000
B 001
C 010
D 011
E 100
F 101
G 110
A 00000
B 00001
C 0001
D 001
E 00
F 10
G 11

Sample Output:

Yes
Yes
No
No

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MIN_WEIGHT	-1

typedef struct TreeNode
{
	int weight;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode, *Tree;

typedef TreeNode ElemType;

typedef struct HeapNode
{
	ElemType *data;
	int size;
	int Capacity;
}HeapNode, *Heap;

typedef Heap MinHeap;

MinHeap MinHeap_new( int MaxSize );
bool IsFull( MinHeap H );
bool IsEmpty( MinHeap H );
bool Insert( MinHeap H, ElemType *e );
ElemType *DeleteMin( MinHeap H );
void PercDown( MinHeap H, int p);
void BuildHeap( MinHeap H );
Tree Huffman_new(  MinHeap H );
int WPL( Tree T, int depth );
int hasPrefixCode(char s[][20], int n);
int isPrefix(char *s1, char *s2);
void Traverse(Tree T);

int main()
{
	int i, j, N, *value;
	char s[10][20], tmp[10], ch;
	scanf("%d", &N);

	value = (int *)malloc(N * sizeof(int));
	MinHeap H = MinHeap_new(N);
	for ( i = 1; i <= N ; ++i )
	{
		scanf(" %c %d", &ch, &H->data[i].weight);
		
		value[i] = H->data[i].weight;
		H->data[i].left = H->data[i].right = NULL;
	}

	BuildHeap( H );
	
	Tree T = Huffman_new( H );

	int n, count, flag;
	scanf("%d", &n);
	for ( i = 1; i <= n ; ++i )
	{
		count = 0;
		for ( j = 1; j <= N ; ++j )
		{
			scanf(" %c%s", &ch, s[j]);
			count += (value[j]*strlen(s[j]));
		}
	
		if (!hasPrefixCode(s, N) && count == WPL(T, 0))
		{
			printf("yes\n");
		}
		else
			printf("no\n");
	}

	return 0;
}
void Traverse(Tree T)
{
	if (T)
	{
		printf("%d ", T->weight);
		Traverse(T->left);
		Traverse(T->right);
	}
}
Tree Huffman_new(  MinHeap H )
{
	Tree T;
	int i, num = H->size;
	for ( i = 0; i < num-1 ; ++i )
	{
		T = (Tree)malloc(sizeof(TreeNode));
		T->left = DeleteMin(H);
		T->right = DeleteMin(H);
		T->weight = (T->left->weight) + (T->right->weight);

		Insert(H, T);
	}
	T = DeleteMin(H);
	return T;
}
int WPL( Tree T, int depth )
{
	if (T->left == NULL && T->right==NULL)
		return depth * (T->weight);
	else
		return WPL(T->left,depth+1) + WPL(T->right,depth+1);
}
MinHeap MinHeap_new(int MaxSize)
{
	MinHeap H = (MinHeap)malloc(sizeof(HeapNode));
	H->data = (ElemType *)malloc((MaxSize+1)*sizeof(ElemType));
	H->data[0].weight = MIN_WEIGHT;
	H->Capacity = MaxSize+5;
	H->size = MaxSize;
	
	return H;
}
bool IsFull( MinHeap H )
{
	return H->size == H->Capacity;
}
bool Insert( MinHeap H, ElemType *e )
{
	int i;
	if ( IsFull( H ) )
	{
		printf("堆已经满了。\n");
		return false;
	}

	i = ++H->size;
	for ( ; H->data[i>>1].weight > (*e).weight ; i >>= 1)
	{
		H->data[i] = H->data[i>>1];
	}
	H->data[i] = *e;
	return true;
}
bool IsEmpty( MinHeap H )
{
	return H->size == 0;
}
ElemType *DeleteMin( MinHeap H )
{
	if ( IsEmpty( H ))
	{
		printf("堆已经为空。\n");
		return NULL;
	}
	ElemType *MinItem, x;
	int child, parent;
	MinItem = (Tree)malloc(sizeof(TreeNode));
	*MinItem = H->data[1];

	x = H->data[H->size--];
	for ( parent = 1; parent<<1 <= H->size; parent = child )
	{
		child = parent<<1;
		if (child != H->size && H->data[child].weight > H->data[child+1].weight)
			++child;
		if (x.weight <= H->data[child].weight)
			break;
		else
			H->data[parent] = H->data[child];
	}
	H->data[parent] = x;
	
	return MinItem;
}
void PercDown( MinHeap H, int p)
{
	ElemType x;
	int child, parent;

	x = H->data[p];

	for ( parent = p; parent<<1 <= H->size; parent = child )
	{
		child = parent<<1;
		if (child != H->size && H->data[child].weight > H->data[child+1].weight)
			++child;
		if (x.weight <= H->data[child].weight)
			break;
		else
			H->data[parent] = H->data[child];
	}
	H->data[parent] = x;	
}
void BuildHeap( MinHeap H )
{
	int i;
 
    for( i = H->size>>1; i > 0; i-- )
        PercDown( H, i );
}
int isPrefix(char *s1, char *s2) 
{      //判断两个字符串是否属于前缀码关系  
    while (s1 && s2 && *s1 == *s2)      //循环至第一个不相同的字母或结束位置  
        ++s1, ++s2;  
    if (*s1 == '\0' || *s2 == '\0')     //如果此时有一个到达结束位置，说明这个字符串一定是另一个字符串的前缀  
        return 1;  
    else  
        return 0;  
}  
int hasPrefixCode(char s[][20], int n)
{//判断n个字符串是否含有前缀码  
	int i, j;
    for ( i = 1; i <= n; ++i)  
        for ( j = i + 1; j <= n; ++j)  
            if (isPrefix(s[i], s[j]))   //两两做对比  
                return 1;  
    return 0;  
}