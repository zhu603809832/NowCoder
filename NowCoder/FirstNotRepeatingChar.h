#pragma once
#include <string>
using namespace std;
#define MAX_LETTER_NUM 26 * 2
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int nRetIndex = -1;
		memset(m_nLetterNum, 0, sizeof(m_nLetterNum));
		memset(m_nLetterIndex, 0, sizeof(m_nLetterIndex));
		for (int i = 0; i < str.size(); ++i)
		{
			int nIndex = str[i] >= 'a' ? str[i] - 'a' + 26: str[i] - 'A';
			++m_nLetterNum[nIndex];
			if (1 == m_nLetterNum[nIndex])
				m_nLetterIndex[nIndex] = i + 1;
			else
				m_nLetterIndex[nIndex] = 0;
		}
		int nMinIndex = INT_MAX;
		for (int i = 0; i < MAX_LETTER_NUM; i++)
		{
			if (m_nLetterIndex[i] > 0 && m_nLetterIndex[i] < nMinIndex)
				nMinIndex = m_nLetterIndex[i];
		}
		nRetIndex = nMinIndex == INT_MAX ? -1 : nMinIndex - 1;
		return nRetIndex;
	}
	bool TestSolution() {
		bool bResult = false;
		int nRetIndex2 = FirstNotRepeatingChar("arPKABWuHcTtlbowHwwZvIdUplXdhAxnncWjFNVYGXsohzPkdQLPvUjSfvEhpMWgIuKcjT");
		bResult = true;
		return bResult;
	}
protected:
	int m_nLetterNum[MAX_LETTER_NUM];
	int m_nLetterIndex[MAX_LETTER_NUM];
};
