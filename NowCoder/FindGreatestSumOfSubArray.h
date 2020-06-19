#pragma once
#include <vector>
using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int nGreatestSum = 0;
		int nSize = array.size();
		if (0 == nSize)
			return nGreatestSum;
		vector<int> vecGreatestDP;
		vecGreatestDP.resize(nSize);
		vecGreatestDP[0] = array[0];
		nGreatestSum = vecGreatestDP[0];
		for (int i = 1; i < nSize; ++i)
		{
			vecGreatestDP[i] = array[i] + vecGreatestDP[i - 1] > array[i] ? array[i] + vecGreatestDP[i - 1] : array[i];
			if (vecGreatestDP[i] > nGreatestSum)
			{
				nGreatestSum = vecGreatestDP[i];
			}
		}
		return nGreatestSum;
	}
	bool TestSolution() {
		bool bResult = false;
		vector<int> vecInput = { 6,-3,-2,7,-15,1,2,2 };
		int nMaxValue = FindGreatestSumOfSubArray(vecInput);

		bResult = true;
		return bResult;
	}

};