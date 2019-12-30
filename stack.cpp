// ConsoleApplication27.cpp : 定义控制台应用程序的入口点。
//设计一个栈，使得PUSH、POP以及GetMin（获取栈中最小元素）能够在常数时间内完成。
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

//使用一个辅助栈来保存最小元素，这个解法简单不失优雅。设该辅助栈名字为minimum stack，其栈顶元素为当前栈中的最小元素。这意味着
//要获取当前栈中最小元素，只需要返回minimum stack的栈顶元素即可。
//每次执行push操作，检查push的元素是否小于或等于minimum stack栈顶元素。如果是，则也push该元素到minimum stack中。
//当执行pop操作的时候，检查pop的元素是否与当前最小值相等。如果相同，则需要将改元素从minimum stack中pop出去。