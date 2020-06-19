#pragma once
//https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

class Solution {
public:
	Solution()
	{
		Calc();
	}
	int Fibonacci(int n) {
		Calc();
		return ms_nFibonacciValue[n];
	}

	void Calc()
	{
		if (false == ms_bInit)
		{
			memset(ms_nFibonacciValue, 0, sizeof(ms_nFibonacciValue));
			ms_nFibonacciValue[1] = 1;
			ms_nFibonacciValue[2] = 1;
			for (int n = 3; n <= 39; ++n)
			{
				ms_nFibonacciValue[n] = ms_nFibonacciValue[n - 1] + ms_nFibonacciValue[n - 2];
			}
			ms_bInit = true;
		}
	}
	bool TestSolution() {
		int nValue1 = Fibonacci(1);
		int nValue2 = Fibonacci(2);
		int nValue3 = Fibonacci(10);
		return nValue2;
	}
protected:
	static bool ms_bInit;
	static int	ms_nFibonacciValue[40];
};

bool Solution::ms_bInit = false;

int Solution::ms_nFibonacciValue[40];
