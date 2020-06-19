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
		//vecResult[N] ΪNʱ�򣬳˻����ֵ
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
//���ӣ�https://www.nowcoder.com/questionTerminal/57d85990ba5b440ab888fc72b0751bf8?f=discussion
//��Դ��ţ����
//
//public class Solution {
//	public int cutRope(int n) {
//	   // n<=3�������m>1����Ҫ�ֶΣ����磺3����ֳ�1��2��1��1��1 ��n=3���ֶγ˻���2,
//		if(n==2)
��//			return 1;
//		if(n==3)
//			return 2;
//		int[] dp = new int[n+1];
//		/*
//		����3����n>=4���������n<=3��ͬ��4���Էֺܶ�Σ�����ֳ�1��3��
//		�����3���Բ���Ҫ�ٷ��ˣ���Ϊ3�ֶ�����2�����־���3����¼���ġ�
//		 */
//dp[1] = 1;
//dp[2] = 2;
//dp[3] = 3;
//int res = 0;//��¼����
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