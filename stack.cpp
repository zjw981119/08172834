// ConsoleApplication27.cpp : �������̨Ӧ�ó������ڵ㡣
//���һ��ջ��ʹ��PUSH��POP�Լ�GetMin����ȡջ����СԪ�أ��ܹ��ڳ���ʱ������ɡ�
#include "stdafx.h"
#include<iostream>
#include<stack>
using namespace std;
class stack1
{
private:
	stack<int>stackpush;
	stack<int>stackMin;
public:
	void push(int a)
	{
		stackpush.push(a);
		if (stackMin.empty() || a <= stackMin.top())
		{
			stackMin.push(a);
		}
	}
	int pop()
	{
		if (stackpush.empty()) return false;
		else
		{
			if (stackpush.top() == stackMin.top())
			{
				stackpush.pop();
				stackMin.pop();
			}
			else
				stackpush.pop();
		}

	}
	int getMin()
	{
		if (stackMin.empty()) return false;
		else cout << stackMin.top();
	}
};
int main()
{
	stack1 sta;
	int n;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		sta.push(a);
	}
	sta.getMin();
	sta.pop();
	return 0;
}

//ʹ��һ������ջ��������СԪ�أ�����ⷨ�򵥲�ʧ���š���ø���ջ����Ϊminimum stack����ջ��Ԫ��Ϊ��ǰջ�е���СԪ�ء�����ζ��
//Ҫ��ȡ��ǰջ����СԪ�أ�ֻ��Ҫ����minimum stack��ջ��Ԫ�ؼ��ɡ�
//ÿ��ִ��push���������push��Ԫ���Ƿ�С�ڻ����minimum stackջ��Ԫ�ء�����ǣ���Ҳpush��Ԫ�ص�minimum stack�С�
//��ִ��pop������ʱ�򣬼��pop��Ԫ���Ƿ��뵱ǰ��Сֵ��ȡ������ͬ������Ҫ����Ԫ�ش�minimum stack��pop��ȥ��