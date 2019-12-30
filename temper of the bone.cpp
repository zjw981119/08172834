// ConsoleApplication22.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;
char map[10][10];
int visit[10][10];
int si, sj, di, dj,wall=0;
int main()
{
	int n, m, t;
	while (cin >> n >> m >> t)
	{
		if (n == 0 && m == 0 && t == 0) break;
		for (int i = 0; i < n; i++)
		{
			cin >> map[i];
		}
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++)
		{
			for (int j =0; j < m; j++)
			{
				if (map[i][j] == 'S')
				{
					si = i;
					sj = j;
				}
				if (map[i][j] == 'D')
				{
					di = i;
					dj = j;
				}
				if (map[i][j] == 'X')
					wall++;
			}
		}
		if (t > n*m - wall - 1)//排除掉不可能情况，当开门时间大于走完所有能走的路的时间
		{
			cout << "NO" << endl;
			wall = 0;
			continue;
		}

	}
	return 0;
}

