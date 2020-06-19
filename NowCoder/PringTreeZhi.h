#pragma once
#include <vector>
#include <queue>
using namespace std;
#define NULL 0

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
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > vecRetResult;
		if (NULL == pRoot)
			return vecRetResult;

		queue<TreeNode*> queueIterTreeNode;
		queue<int> queueDepth;
		queueIterTreeNode.push(pRoot);
		queueDepth.push(0);
		while (queueIterTreeNode.size())
		{
			TreeNode* pTreeNode = queueIterTreeNode.front();
			int nCurDepth = queueDepth.front();
			queueIterTreeNode.pop();
			queueDepth.pop();
			if (nCurDepth >= vecRetResult.size())
			{
				vector<int> vecTemp;
				vecTemp.push_back(pTreeNode->val);
				vecRetResult.push_back(vecTemp);
			}
			else
			{
				vecRetResult[nCurDepth].push_back(pTreeNode->val);
			}
			if (pTreeNode->left)
			{
				queueIterTreeNode.push(pTreeNode->left);
				queueDepth.push(nCurDepth + 1);
			}

			if (pTreeNode->right)
			{
				queueIterTreeNode.push(pTreeNode->right);
				queueDepth.push(nCurDepth + 1);
			}
		}
		for (int i = 0; i < vecRetResult.size(); ++i)
		{
			bool bReverse = i % 2 ? true : false;
			if (bReverse)
			{
				for (int j = 0; j < vecRetResult[i].size() / 2; ++j)
				{
					int nTemp = vecRetResult[i][j];
					vecRetResult[i][j] = vecRetResult[i][vecRetResult[i].size() - 1 - j];
					vecRetResult[i][vecRetResult[i].size() - 1 - j] = nTemp;
				}
			}
		}
		return vecRetResult;
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
		pNode1->left = pNode2;
		pNode1->right = pNode3;
		pNode2->left = pNode4;
		pNode2->right = pNode5;
		pNode3->left = pNode6;
		pNode3->right = pNode7;
		pNode4->left = pNode8;
		pNode4->right = pNode9;
		vector<vector<int> >  ret = Print(pNode1);
		bResult = true;
		return bResult;
	}
};