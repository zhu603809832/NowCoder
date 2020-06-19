#pragma once
#include <vector>
using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		bool bResult = true;
		int nSize = sequence.size();
		if (0 == nSize)
			return false;

		if (1 == nSize)
			return true;

		int nRootValueIndex = nSize - 1;
		int nRightTreeBeginIndex = GetBiggerIndex(sequence, nRootValueIndex, 0, nSize - 1);
		int nRightTreeEndIndex = nRootValueIndex - 1;
		int nLeftTreeBeginIndex = 0;
		int nLeftTreeEndIndex = nRightTreeBeginIndex - 1;
		bResult = IsSquence(sequence, nRootValueIndex, nLeftTreeBeginIndex, nLeftTreeEndIndex, nRightTreeBeginIndex, nRightTreeEndIndex);
		return bResult;
	}
	
	bool IsSquence(const vector<int>& sequence, int nRootIndex, int nTreeLeftBeginIndex, int nTreeLeftEndIndex, int nTreeRightBeginIndex, int nTreeRightEndIndex)
	{
		bool bResult = true;
		bool bCompare = false;
		if (nRootIndex < 0)
			return bResult;

		int nRootValue = sequence[nRootIndex];
		for (int i = nTreeLeftBeginIndex; i >= 0 && i <= nTreeLeftEndIndex; i++)
		{
			bResult = bResult && (sequence[i] < nRootValue);
			bCompare = true;
		}

		for (int i = nTreeRightBeginIndex; i >= 0 && i <= nTreeRightEndIndex; ++i)
		{
			bResult = bResult && (sequence[i] > nRootValue);
			bCompare = true;
		}
		if (false == bCompare)
			return bResult;

		int nLeftTreeNewRootIndex = nTreeLeftEndIndex;
		int nRightTreeNewBeginIndex = GetBiggerIndex(sequence, nLeftTreeNewRootIndex, nTreeLeftBeginIndex, nTreeLeftEndIndex);
		int nRightTreeNewEndIndex = nLeftTreeNewRootIndex - 1;
		int nLeftTreeNewBeginIndex = nTreeLeftBeginIndex;
		int nLeftTreeNewEndIndex = nRightTreeNewBeginIndex - 1;
		bool bLeftTreeIsSquence = IsSquence(sequence, nLeftTreeNewRootIndex, nLeftTreeNewBeginIndex, nLeftTreeNewEndIndex, nRightTreeNewBeginIndex, nRightTreeNewEndIndex);

		int nRigthTreeNewRootIndex = nTreeRightEndIndex;
		int nRightTreeBeginIndex = GetBiggerIndex(sequence, nRigthTreeNewRootIndex, nTreeRightBeginIndex, nTreeRightEndIndex);
		int nRightTreeEndIndex = nRigthTreeNewRootIndex - 1;
		int nRightTreeLeftBeginIndex = nTreeRightBeginIndex;
		int nRightTreeLeftEndIndex = nRightTreeBeginIndex - 1;
		bool bRightTreeIsSquence = IsSquence(sequence, nRigthTreeNewRootIndex, nRightTreeLeftBeginIndex, nRightTreeLeftEndIndex, nRightTreeBeginIndex, nRightTreeEndIndex);
		bResult = bResult && bLeftTreeIsSquence && bRightTreeIsSquence;
		return bResult;
	}

	int GetBiggerIndex(const vector<int>& sequence, int nTargetIndex, int nBeginIndex, int nEndIndex)
	{
		int nRetIndex = -1;
		for (int i = nBeginIndex; i <= nEndIndex; ++i)
		{
			if (sequence[i] > sequence[nTargetIndex])
				return i;
		}
		return nRetIndex;
	}
	bool TestSolution() {
		bool bResult = false;
		vector<int> vecTest = { 1,4,7,6,3,13,14,10,8 };
		vector<int> vecTest1 = { 2,9,5,11,17,15,19,11,12 };
		bool bRetCode = VerifySquenceOfBST(vecTest);
		bool bRetCode1 = VerifySquenceOfBST(vecTest1);
		bResult = true;
		return bResult;
	}
};