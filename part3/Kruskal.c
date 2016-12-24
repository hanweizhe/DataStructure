/*最小生成树 Kruskal算法*/
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#define M 20
#define MAX 20


typedef	struct 
{
	int begin,  end;
	int weight;
}edge;
edge edges[MAX];

/*邻接矩阵*/
typedef struct
{
	int adj;
	int weight;
}AdjMatrix[MAX][MAX];

typedef struct 
{
	AdjMatrix arc;
	int vexnum, arcnum;
}MGraph;

/*函数声明*/
void CreateGraph(MGraph *);
void sort(edge *, MGraph *);
void MiniSpanTree(MGraph *);
int find(int *, int );
void Swapn(edge *, int , int);

int main()
{
	MGraph *G;
	G = (MGraph *)malloc(sizeof(MGraph));
	if (G == NULL){
		printf("Memory allcation failed, goodbye\n");
		exit(1);
	}
	CreateGraph(G);
	MiniSpanTree(G);
	system("pause");
	return 0;
}

void CreateGraph(MGraph * G)
{
	int i, j, m, n;
	printf("请输入边数和顶点数:");
	scanf("%d %d", &G->arcnum, &G->vexnum);
	for ( i = 1; i <= G->vexnum; ++i) 
	{
		for (j = 1; j <= G->vexnum; ++j) 
		{
			G->arc[i][j].adj = 0;
			G->arc[j][i].adj = 0;
		}
	}

	for ( i = 1; i <= G->arcnum; ++i)
	{
		printf("\n请输入有边的两个顶点");
		scanf("%d %d", &n, &m);
		while ( n < 0 || n > G->vexnum || m < 0 || m > G->vexnum)
		{
			printf("输入的数字不符合要求，请重新输入：");
			scanf("%d %d", &n, &m);
		}

		G->arc[n][m].adj = G->arc[m][n].adj = 1;
		getchar();
		printf("\n请输入%d与%d之间的权值", n, m);
		scanf("%d", &G->arc[n][m].weight);
	}

	printf("邻接矩阵为：\n");
	for ( i = 1; i <= G->vexnum; ++i)
	{
		for ( j = 1; j <= G->vexnum; ++j)
		{
			printf("%3d ", G->arc[i][j].adj);
		}
		printf("\n");
	}

}

void sort(edge edges[], MGraph * G)   //对权值进行排序
{
	int i, j;
	for ( i = 1; i < G->arcnum; ++i)
	{
		for ( j = 1; j <= G->arcnum - i; ++j)
		{
			if (edges[j].weight > edges[j+1].weight)
			{
				Swapn(edges, j, j+1);
			}
		}
	}
	printf("权值排序之后为：\n");
	for ( i = 1; i <= G->arcnum; ++i)
	{
		printf("<< %d, %d >>    %d\n", edges[i].begin, edges[i].end, edges[i].weight);
	}
}

/*交换权值以及头和尾*/
void Swapn( edge * edges, int i, int j)
{
	int temp;
	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;

	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;

	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;
}

/*生成最小生成树*/
void MiniSpanTree(MGraph * G)
{
	int i, j, m, n;
	int k=1;
	int parent[M];
	for ( i = 1; i < G->vexnum; ++i)
	{
		for ( j = i+1; j <= G->vexnum; ++j)
		{
			if (G->arc[i][j].adj == 1)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = G->arc[i][j].weight;
				k++;
			}			
		}
	}

	sort(edges, G);
	for ( i = 1; i <= G->arcnum; ++i)
	{
		parent[i] = 0;
	}
	printf("最小生成树为：\n");
	for ( i = 1; i <= G->arcnum; ++i)
	{
		n = find(parent, edges[i].begin);
		m = find(parent, edges[i].end);
		if (n != m){
			parent[n] = m;
			printf("<< %d, %d >>    %d\n", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}

/*找尾*/
int find(int * parent, int f)
{
	while (parent[f] > 0){
		f = parent[f];
	}
	return f;
}


