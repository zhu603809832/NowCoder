#pragma once
//https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#define MAX_NUM 40
class Solution {
public:
	int jumpFloor(int number) {
		CalcFibonacci();
		int nRetValue = 0;
		nRetValue = ms_nValue[number];

		return nRetValue;
	}

	bool CalcFibonacci()
	{
		bool bResult = false;
		if (false == ms_bInit)
		{
			ms_nValue[1] = 1;
			ms_nValue[2] = 2;
			ms_bInit = true;
			for (int i = 3; i <= MAX_NUM; ++i)
			{
				ms_nValue[i] = ms_nValue[i - 2] + ms_nValue[i - 1];
			}
		}

		bResult = false;
	
		return bResult;
	}
	bool TestSolution() {
		int nValue1 = jumpFloor(1);
		int nValue2 = jumpFloor(2);
		int nValue3 = jumpFloor(5);
		int nValue4 = jumpFloor(20);
		return true;
	}
protected:
	static bool ms_bInit;
	static int ms_nValue[MAX_NUM + 1];
};

bool Solution::ms_bInit = false;

int Solution::ms_nValue[MAX_NUM + 1];
