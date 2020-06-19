#pragma once
class Solution {
public:
	int Sum_Solution(int n) {
		if (n == 0)
			return 0;
		return Sum_Solution(n - 1) + n;
	}
	bool TestSolution() {
		bool bResult = false;
		int nResult = Sum_Solution(5);
		int nResult1 = Sum_Solution(1);
		bResult = true;
		return bResult;
	}
};