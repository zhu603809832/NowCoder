#pragma once
//https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		bool bResult = false;
		for (int i = 0; i < length; ++i)
		{
			int nCurNum = numbers[i];
			for (int j = i + 1; j < length; ++j)
			{
				int nTempNum = numbers[j];
				if (nTempNum == nCurNum)
				{
					*duplication = nTempNum;
					bResult = true;
					return bResult;
				}
			}
		}
		return bResult;
	}
	bool TestSolution() {
		bool bResult = false;
		
		int numbers[] = { 3,3, 1,0,2,5,3 };
		int nCount = sizeof(numbers) / sizeof(numbers[0]);
		int nDulication = 0;
		bool bRetResult = duplicate(numbers, nCount, &nDulication);
		bResult = true;
		return bResult;
	}
};