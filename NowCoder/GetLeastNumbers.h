#pragma once
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> vecRetResuolt;
		int nNumCount = input.size();
		if (0 == nNumCount)
			return vecRetResuolt;

		if (k >= nNumCount)
		{
			vecRetResuolt = input;
			return vecRetResuolt;
		}

		return vecRetResuolt;
	}
	bool SortNumbers(vector<int> &numbers, int &nForcusIndex, int nBeginIndex, int nEndIndex)
	{
		bool bResult = false;
		int nCurForcusIndex = nForcusIndex;
		int nForcusNum = numbers[nForcusIndex];
		for (int nIndex = nBeginIndex; nIndex < nEndIndex; nIndex++)
		{
			if (numbers[nIndex] > nForcusNum && nIndex < nCurForcusIndex)
			{
				int nTempNum = numbers[nIndex];
				for (int j = nIndex ; j < nCurForcusIndex; ++j)
				{
					numbers[j] = numbers[j + 1];
				}
				numbers[nCurForcusIndex] = nTempNum;
				nCurForcusIndex = nCurForcusIndex - 1;
				--nIndex;
			}
			else if (numbers[nIndex] < nForcusNum && nIndex > nCurForcusIndex)
			{
				int nTempNum = numbers[nIndex];
				for (int j = nCurForcusIndex; j < nIndex; ++j)
				{
					numbers[j + 1] = numbers[j];
				}
				numbers[nCurForcusIndex] = nTempNum;
				nCurForcusIndex = nCurForcusIndex + 1;
				++nIndex;
			}
		}
		nForcusIndex = nCurForcusIndex;
		bResult = true;
		return bResult;
	}
};