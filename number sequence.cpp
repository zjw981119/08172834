// ConsoleApplication19.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
int fac(int, int, int);
using namespace std;
int main()
{
	int A, B, n, mark;
	int b[1000] = { 0 ,1,1 };
	while (cin >> A >> B >> n)
	{
		if (A==0&&B==0&&n==0)
			break;
		for (int j = 3; j < 1000; j++)//Ѱ��ѭ������
		{
			b[j] = fac(A, B, j);
			if (b[j]==1 && b[j - 1]==1)
			{
				mark = j - 2;//j-2Ϊѭ������
				break;
			}
		}
		cout << fac(A, B, n%mark) << endl;
	}
	return 0;
}

int fac(int A, int B, int n) //�ݹ麯��
{
	int c;
	if (n == 1||n==2)
		c = 1;
	else if (n>2)
		c = (A*fac(A, B, n - 1) + B*fac(A, B, n - 2)) % 7;
	return c;
}
