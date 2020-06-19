#pragma once
//https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int nRetValue = 0;
		int nStackSize1 = stack1.size();
		if (0 == nStackSize1)
			return nRetValue;

		while (nStackSize1 != 1)
		{
			int nTopValue = stack1.top();
			stack1.pop();
			stack2.push(nTopValue);
			--nStackSize1;
		}
		nRetValue = stack1.top();
		stack1.pop();

		while (stack2.size())
		{
			int nTopValueTemp = stack2.top();
			stack2.pop();
			stack1.push(nTopValueTemp);
		}
		return nRetValue;
	}
	bool TestSolution() {
		for (int i = 0; i < 5; ++i)
		{
			push(i);
		}

		for (int i = 0; i < 5; ++i)
		{
			cout << pop() << endl;
		}
		return true;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};

/*

class Solution
{
public:
void push(int node) {
stack1.push(node);
}

链接：https://www.nowcoder.com/questionTerminal/54275ddae22f475981afa2244dd448c6?f=discussion
来源：牛客网

int pop() {
int a;
if(stack2.empty()){
while(!stack1.empty()){
a=stack1.top();
stack2.push(a);
stack1.pop();
}
}
a=stack2.top();
stack2.pop();
return a;

}
private:
stack<int> stack1;
stack<int> stack2;
};
*/