#pragma once

#include <vector>
using namespace std;

#define  NULL 0

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int> > vecRetResult;
		vector<vector<int> > vecAllPath;
		if (NULL == root)
			return vecRetResult;

		vector<int> tempPath;
		//Get All
		TraverseTree(root, tempPath, vecAllPath);
		//Filter
		for (int i = 0 ; i < vecAllPath.size(); ++i)
		{
			const vector<int> & vecTempPath = vecAllPath[i];
			int nSum = 0;
			for (int j = 0; j < vecTempPath.size(); ++j)
			{
				nSum += vecTempPath[j];
			}
			if (nSum == expectNumber)
				vecRetResult.push_back(vecTempPath);
		}
		//Sorted
		for (int i = 0; i < vecRetResult.size(); ++i)
		{
			vector<int> vecCurPath = vecRetResult[i];
			for (int j = i + 1; j < vecRetResult.size(); ++j)
			{
				vector<int> vecComparePath = vecRetResult[j];
				if (vecCurPath.size() < vecComparePath.size())
				{
					vector<int> vecTempPath = vecCurPath;
					vecCurPath = vecComparePath;
					vecComparePath = vecTempPath;

					vecRetResult[i] = vecCurPath;
					vecRetResult[j] = vecComparePath;
				}
			}
		}
		return vecRetResult;
	}
	void TraverseTree(TreeNode* root, vector<int> vecTraversePath, vector<vector<int> >& vecAllPath)
	{
		if (NULL == root)
			return;

		vecTraversePath.push_back(root->val);
		if (root->left)
			TraverseTree(root->left, vecTraversePath, vecAllPath);

		if (root->right)
			TraverseTree(root->right, vecTraversePath, vecAllPath);

		if (NULL == root->left && NULL == root->right)
			vecAllPath.push_back(vecTraversePath);

		return;
	}
	bool TestSolution() {
		bool bResult = false;
		TreeNode* pNode1 = new TreeNode(1);
		TreeNode* pNode2 = new TreeNode(2);
		TreeNode* pNode3 = new TreeNode(3);
		TreeNode* pNode4 = new TreeNode(4);
		TreeNode* pNode5 = new TreeNode(5);
		TreeNode* pNode6 = new TreeNode(6);
		TreeNode* pNode7 = new TreeNode(7);
		TreeNode* pNode8 = new TreeNode(8);
		TreeNode* pNode9 = new TreeNode(9);
		TreeNode* pNode10 = new TreeNode(10);
		TreeNode* pNode11 = new TreeNode(11);

		pNode1->left = pNode6;
		pNode1->right = pNode10;

		pNode6->left = pNode5;
		pNode6->right = pNode2;
		pNode2->left = new TreeNode(2);
		pNode2->right = new TreeNode(3);

		pNode10->left = new TreeNode(1);
		pNode10->right = new TreeNode(2);

		vector<vector<int> > vecAllPath = FindPath(pNode1, 12);
		bResult = true;
		return bResult;
	}
};