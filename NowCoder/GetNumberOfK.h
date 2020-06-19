#pragma once
#include <vector>
using namespace std;
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int nResult = 0;
		if (data.size() == 0)
			return nResult;

		for (int i = 0; i < data.size(); ++i)
		{
			if (data[i] == k)
			{
				nResult++;
			}
		}
		return nResult;
	}
	bool TestSolution() {
		bool bResult = false;
		int a[] = { 1, 2, 3, 4, 4, 5, 6, 7, 8 };
		vector<int> vecTest(a, a + 9);
		int nResult = GetNumberOfK(vecTest, 4);
		bResult = true;
		return bResult;
	}
};

���ӣ�https://www.nowcoder.com/questionTerminal/70610bf967994b22bb1c26f9ae901fa2?f=discussion
��Դ��ţ����

//��Ϊdata�ж������������Կ�����΢��һ�£���������k������λ�ã���������k-0.5��k+0.5
//��������Ӧ�ò����λ�ã�Ȼ��������ɡ�
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		return biSearch(data, k + 0.5) - biSearch(data, k - 0.5);
	}
private:
	int biSearch(const vector<int> & data, double num) {
		int s = 0, e = data.size() - 1;
		while (s <= e) {
			int mid = (e - s) / 2 + s;
			if (data[mid] < num)
				s = mid + 1;
			else if (data[mid] > num)
				e = mid - 1;
		}
		return s;
	}
};