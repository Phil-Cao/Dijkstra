#include<iostream>
using namespace std;
int **gra;//[7][7] = {0,2,0,1,0,0,0, 0,0,0,3,10,0,0, 4,0,0,0,0,5,0, 0,0,2,0,2,8,4, 0,0,0,0,0,0,6, 0,0,0,0,0,0,0, 0,0,0,0,0,1,0};

struct Vertex
{
	int known;
	int d;
	int p;
};
Vertex *sta;

void build(int a)//利用邻接矩阵存储有向图gra，且用结构体数组对每个节点进行扩展
{
	sta = new Vertex[a];
	for (int i = 0; i < a; i++)
	{
		sta[i].d = -1;
		sta[i].known = 0;
		sta[i].p = -1;
	}
}

void display(int a)
{
	cout << "Vextex    d    piorVextex" << endl;
	for (int i = 0; i < a; i++)
	{
		cout << "   " << i + 1 << "      " << sta[i].d << "         " << sta[i].p + 1 << endl;
	}
}

void Dij(int a)//开始实现迪杰斯特拉算法
{
	int i = 0;
	int j = 0;
	int cur = i;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a; j++)//对每一个当前节点可以到达的节点进行分析
		{
			if (gra[cur][j] != 0&&sta[j].known==0)
			{
				sta[cur].known = 1;
				if (sta[j].d == -1)//未被分析过的情况
				{
					if (cur == 0)
					{
						sta[j].d = gra[cur][j];
					}
					else
					{
						sta[j].d = sta[cur].d + gra[cur][j];
					}
					sta[j].p = cur;
					//sta[j].known = 1;
				}
				else//若已被分析过，则比较现情况是否更优
				{
					if (sta[cur].d + gra[cur][j] <= sta[j].d)
					{
						sta[j].d = sta[cur].d + gra[cur][j];
						sta[j].p = cur;
					}
				}
			}
		}
		int tempd = 10000;
		for (j = 0; j < a; j++)//选取下一个拓展的顶点
		{
			if (sta[j].known == 0&&sta[j].d!=-1)
			{
				if (sta[j].d < tempd)
				{
					cur = j;
					tempd = sta[j].d;
				}
			}
		}
		display(a);
	}
}

int main()
{
	int v;
	cout << "Please input the numbers of vertexs: " << endl;
	cin >> v;
	gra = new int *[v];
	for (int i = 0; i < v; i++)
	{
		gra[i] = new int[v];
	}
    for (int i = 0; i<v; i++)
        for (int j = 0; j<v; j++)
            cin >> gra[i][j];
	build(v);
	Dij(v);
	display(v);
	system("pause");
}
