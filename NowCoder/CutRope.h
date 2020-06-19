#pragma once
#include <vector>
using namespace std;
class Solution {
public:
	int cutRope(int number) {
		if (2 == number)
			return 1;

		if (3 == number)
			return 2;

		int nArraySize = number / 2 + 1;
		vector<int> vecResult;
		vecResult.resize(nArraySize);
		//vecResult[N] 为N时候，乘积最大值
		int nMaxValue = 0;
		for (int i = 2; i < nArraySize; ++i)
		{
			vecResult[i] = GetMultiplyValue(number, i);
			if (vecResult[i] > nMaxValue)
				nMaxValue = vecResult[i];

			if (i - 1 >= 0 && vecResult[i - 1] > vecResult[i])
				break;
		}
		return nMaxValue;
	}

	int GetMultiplyValue(int number, int n)
	{
		int nRetValue = 1;
		int nShang = number / n;
		int nMod = number % n;
		nRetValue = Power(nShang + 1, nMod) * Power(nShang, n - nMod);
		return nRetValue;
	}

	int Power(int nX, int exp)
	{
		int nRetValue = 1;
		for (int i = 0; i < exp; ++i)
		{
			nRetValue *= nX;
		}
		return nRetValue;
	}
	bool TestSolution()
	{
		int nValue11 = cutRope(2);
		int nValue12 = cutRope(3);
		int nValue19 = cutRope(4);
		int nValue0 = cutRope(8);
		int nValue1 = cutRope(18);
		int nValue2 = cutRope(20);
		int nValue3 = cutRope(50);
		return true;
	}
};


///*
//链接：https://www.nowcoder.com/questionTerminal/57d85990ba5b440ab888fc72b0751bf8?f=discussion
//来源：牛客网
//
//public class Solution {
//	public int cutRope(int n) {
//	   // n<=3的情况，m>1必须要分段，例如：3必须分成1、2；1、1、1 ，n=3最大分段乘积是2,
//		if(n==2)
·//			return 1;
//		if(n==3)
//			return 2;
//		int[] dp = new int[n+1];
//		/*
//		下面3行是n>=4的情况，跟n<=3不同，4可以分很多段，比如分成1、3，
//		这里的3可以不需要再分了，因为3分段最大才2，不分就是3。记录最大的。
//		 */
//dp[1] = 1;
//dp[2] = 2;
//dp[3] = 3;
//int res = 0;//记录最大的
//for (int i = 4; i <= n; i++) {
//	for (int j = 1; j <= i / 2; j++) {
//		res = Math.max(res, dp[j] * dp[i - j]);
//	}
//	dp[i] = res;
//}
//return dp[n];
//	}
//}
//*/