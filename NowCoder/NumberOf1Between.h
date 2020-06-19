#pragma once

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int nRetCount = 0;
		for (int i = 1; i <= n; ++i)
		{
			nRetCount += CalcCount(i);
		}
		return nRetCount;
	}
	int CalcCount(int n) {
		int nCount = 0;
		int nTemp = n;
		while (nTemp)
		{
			int nLeft = nTemp % 10;
			if (nLeft == 1)
				nCount++;
			nTemp = nTemp / 10;
		}
		return nCount;
	}
	bool TestSolution() {
		bool bResult = false;
		
		int nValue = NumberOf1Between1AndN_Solution(13);
		int nValue2 = NumberOf1Between1AndN_Solution(1);
		bResult = true;
		return bResult;
	}
};