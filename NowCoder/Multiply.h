#pragma once
//https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> vecRetResult;
		int nCount = A.size();
		if (0 == nCount)
		{
			return vecRetResult;
		}
		
		vecRetResult.resize(nCount);
		for (int i = 0; i < nCount; ++i)
		{
			vecRetResult[i] = 1;
		}

		for (int i = 0; i < nCount; ++i)
		{
			int nCurNum = A[i];
			for (int j = 0; j < nCount; ++j)
			{
				if (i != j)
				{
					vecRetResult[j] *= nCurNum;
				}
			}
		}
		return vecRetResult;
	}
	bool TestSolution() {
		bool bResult = false;
		int nNum[] = { 1,2,3,4,5 };
		vector<int> A(nNum, nNum + 5);
		
		vector<int> vecResult = multiply(A);
		bResult = true;
		return bResult;
	}
};

/*
���ӣ�https://www.nowcoder.com/questionTerminal/94a4d381a68b47b7a8bed86f2975db46?f=discussion
��Դ��ţ����

<����>��
�����´��룬���������СΪ5��
���ڵ�һ��forѭ��
��һ����b[0] = 1;
�ڶ�����b[1] = b[0] * a[0] = a[0]
��������b[2] = b[1] * a[1] = a[0] * a[1];
���Ĳ���b[3] = b[2] * a[2] = a[0] * a[1] * a[2];
���岽��b[4] = b[3] * a[3] = a[0] * a[1] * a[2] * a[3];
Ȼ����ڵڶ���forѭ��
��һ��
temp *= a[4] = a[4];
b[3] = b[3] * temp = a[0] * a[1] * a[2] * a[4];
�ڶ���
temp *= a[3] = a[4] * a[3];
b[2] = b[2] * temp = a[0] * a[1] * a[4] * a[3];
������
temp *= a[2] = a[4] * a[3] * a[2];
b[1] = b[1] * temp = a[0] * a[4] * a[3] * a[2];
���Ĳ�
temp *= a[1] = a[4] * a[3] * a[2] * a[1];
b[0] = b[0] * temp = a[4] * a[3] * a[2] * a[1];
�ɴ˿��Կ�����b[4]��b[0]���Ѿ��õ���ȷ���㡣
class Solution {
public:
vector<int> multiply(const vector<int>& A) {
vector<int> vec;
int sz=A.size();
if(sz==0)
return vec;
vec.push_back(1);
for(int i=0;i<sz-1;i++)
vec.push_back(vec.back()*A[i]);
int tmp=1;
for(int i=sz-1;i>=0;i--)
{
vec[i]=vec[i]*tmp;
tmp=tmp*A[i];
}
return vec;
}
};
*/