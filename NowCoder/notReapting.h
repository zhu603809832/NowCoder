#pragma once
#include <string>

const int MAX_CHAR_NUM = 'z' - 'A';
using namespace std;

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int nRetIndex = -1;
		memset(m_nCount, 0, sizeof(m_nCount));
		for (int i = 0; i < str.size(); ++i)
		{
			char strChar = str[i];
			int nOffset = strChar - 'A';
			m_nCount[nOffset]++;
		}
		for (int i = 0; i < str.size(); ++i)
		{
			char strChar = str[i];
			int nOffset = strChar - 'A';
			if (1 == m_nCount[nOffset])
			{
				nRetIndex = i;
				return nRetIndex;
			}
		}
		return nRetIndex;
	}
	bool TestSolution() {
		bool bResult = false;
		int nIndex = FirstNotRepeatingChar("akdkkflaldeieqodAOKKOUH");

		bResult = true;
		return bResult;
	}
private:
	int m_nCount[MAX_CHAR_NUM + 1];
};