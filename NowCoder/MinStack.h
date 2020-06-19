#pragma once
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
	void push(int value) {
		m_curStack.push(value);
		if (m_minStack.empty())
			m_minStack.push(value);
		else
		{
			int nCurMin = m_minStack.top();
			if (value <= nCurMin)
				m_minStack.push(value);
		}
	}
	void pop() {
		int nTopValue = m_curStack.top();
		m_curStack.pop();
		int nTopMinValue = m_minStack.top();
		if (nTopValue == nTopMinValue)
			m_minStack.pop();

	}
	int top() {
		int nTop = m_curStack.top();
		return nTop;
	}
	int min() {
		int nTopMin = m_minStack.top();
		return nTopMin;
	}
private:
	stack<int> m_curStack;
	stack<int> m_minStack;

public:
	bool TestSolution() {
		bool bResult = false;
		push(1);
		push(-1);
		push(-2);
		push(0);
		int nMinValue = min();
		int nTop = top();
		pop();
		pop();
		nMinValue = min();
		nTop = top();

		bResult = true;
		return bResult;
	}
};