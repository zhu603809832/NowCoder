#pragma once
//https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		bool bFindResult = false;
		int nRowCount = array.size();
		if (0 == nRowCount)
			return bFindResult;

		int nColumn = array[0].size();
		if (0 == nColumn)
			return bFindResult;

		for (int i = 0; i < nRowCount; ++i)
		{
			for (int j = 0 ; j < nColumn; ++j)
			{
				if (array[i][j] == target)
				{
					bFindResult = true;
					return bFindResult;
				}
				
			}
		}

		return bFindResult;
	}
};