// ConsoleApplication25.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct Linknode
{
	Linknode(int a)
	{
		data = a;
		link = NULL;
	}
	int data;
	Linknode *link;
};

class Josephus
{
public:
	Josephus(int n, int k,int m)
	{
		jn = n;
		jk = k;
		jm = m;
		creatlink();
		output();
	}
protected:
	void creatlink();
	void output();
private:
	int jn, jk, jm;
	Linknode *first;
};
void Josephus::creatlink()                    //产生循环链表
{
	Linknode *p = new Linknode(1);
	Linknode *curr = p;
	first = p;
	for (int i = 2; i < jn+1; i++)
	{
	    curr = new Linknode(i);
		p->link = curr;
		p = curr;
	}
	curr->link = first;
}
void Josephus::output()
{
	Linknode *p=first;
	Linknode *curr = p;
	for (int i = 1; i < jk; i++)//寻找开始报数的人
	{
		curr = curr->link;
	}
	int num = jn;
	while (num != 1)//排除报数为m的人
	{
		for (int i = 1; i < jm; i++)
		{
			p = curr;
			curr = p->link;
		}
		Linknode *del;//删除节点
		del = curr;
		p->link = del->link;
		curr = del->link;
		delete del;
		num--;
	}
	cout << curr->data << endl;
}
int main()
{
	int n, k, m;
	cin >> n >> k >> m;
	Josephus josephus(n,k,m);
	return 0;
}

