#pragma once
#include <vector>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int nRetValue = 0;
		int nCount = numbers.size();
		if (0 == nCount)
			return nRetValue;

		if (1 == nCount)
			return numbers[0];

		int nValueCount = 1;
		nRetValue = numbers[0];
		for (int i = 1; i < nCount; ++i)
		{
			if (nRetValue == numbers[i])
				++nValueCount;
			else
				--nValueCount;

			if (nValueCount <= 0)
			{
				nValueCount = 1;
				nRetValue = numbers[i];
			}
		}

		int nLastCount = 0;
		for (int i = 0 ; i < nCount; ++i)
		{
			if (numbers[i] == nRetValue)
				++nLastCount;
		}
		nRetValue = nLastCount > nCount / 2 ? nRetValue : 0;
			
		return nRetValue;
	}
	bool TestSolution() {
		int a[] = { 1,2,3,2,3,4,5,2,3,4,2 ,2,2,2,2};
		vector<int> numbers(a, a + sizeof(a) / sizeof(a[0]));

		int nRetValue = MoreThanHalfNum_Solution(numbers);
		return true;
	}
};