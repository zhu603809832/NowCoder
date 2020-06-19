#pragma once
#include <vector>
using namespace std;

struct PATH_CHANGE
{
	int nRowOffset;
	int nColumnOffset;
};

enum TRUN_DIRECTION {
	ENUM_TRUN_RIGHT,
	ENUM_TRUN_DOWN,
	ENUM_TRUN_LEFT,
	ENUM_TRUN_UP,
	ENUM_TRUN_COUNT,
};

PATH_CHANGE s_Change[ENUM_TRUN_COUNT] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0},
};

class Solution {
public:
	
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> vecRetResult;
		int nRow = matrix.size();
		if (nRow == 0)
			return vecRetResult;

		int nColumn = matrix[0].size();
		m_vecTraversePath.clear();
		m_vecTraversePath.resize(nRow);
		for (int i = 0; i < nRow; ++i)
			m_vecTraversePath[i].resize(nColumn, 0);

		TRUN_DIRECTION emCurDirection = ENUM_TRUN_RIGHT;
		int nCurPosX = 0;
		int nCurPosY = 0;

		while (1)
		{
			if (0 == m_vecTraversePath[nCurPosX][nCurPosY])
			{
				vecRetResult.push_back(matrix[nCurPosX][nCurPosY]);
				m_vecTraversePath[nCurPosX][nCurPosY] = 1;
			}
			
			if (vecRetResult.size() == nRow * nColumn)
				break;

			int nNextPosX = s_Change[emCurDirection].nRowOffset + nCurPosX;
			int nNextPosY = s_Change[emCurDirection].nColumnOffset + nCurPosY;
			if (nNextPosX >= 0 && nNextPosX < nRow && 
				nNextPosY >= 0 && nNextPosY < nColumn &&
				0 == m_vecTraversePath[nNextPosX][nNextPosY])
			{
				nCurPosX = nNextPosX;
				nCurPosY = nNextPosY;
			}
			else
			{
				emCurDirection = static_cast<TRUN_DIRECTION>((emCurDirection + 1) % ENUM_TRUN_COUNT);
			}
		}
		
		return vecRetResult;
	}
	
	bool TestSolution() {
		bool bResult = false;
		vector<vector<int> > vecTest;
		vector<int > vecPrintResult;
		int m = 4;
		int n = 4;
		for (int i = 0; i < m; ++i)
		{
			vector<int> vecTemp;
			for (int j = 0; j < n; ++j)
			{
				vecTemp.push_back(i * n + j + 1);
			}
			vecTest.push_back(vecTemp);
		}
		vecPrintResult = printMatrix(vecTest);
		bResult = true;
		return bResult;
	}
protected:
	vector<vector<int> > m_vecTraversePath;
};