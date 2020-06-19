#pragma once
//https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

#define MAX_NUM 32
class Solution {
public:
	int jumpFloorII(int number) {
		Calc();
		return ms_nValue[number];
	}

	bool Calc() {
		if (false == ms_bInit)
		{
			ms_nValue[0] = 0;
			ms_nValue[1] = 1;
			ms_nValue[2] = 1 + ms_nValue[1];
			ms_nValue[3] = 1 + ms_nValue[2] + ms_nValue[1];
			for (int i = 4; i <= MAX_NUM; ++i)
			{
				int nSum = 1;
				for (int j = i - 1; j >= 0; --j)
				{
					nSum += ms_nValue[j];
				}
				ms_nValue[i] = nSum;
			}
			ms_bInit = true;
		}
		return true;
	}

	bool TestSolution() {
		bool bResult = false;
		int nValue1 = jumpFloorII(2);
		int nValue2 = jumpFloorII(5);
		int nValue3 = jumpFloorII(9);

		bResult = true;
		return bResult;
	}
protected:
	static bool ms_bInit;
	static unsigned int ms_nValue[MAX_NUM + 1];
};

bool Solution::ms_bInit = false;

unsigned int Solution::ms_nValue[MAX_NUM + 1];
