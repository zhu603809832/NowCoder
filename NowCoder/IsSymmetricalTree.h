#pragma once
#include <vector>
#include <queue>
#define NULL 0
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
#define INVALID_VALUE -99
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		bool bResult = true;
		if (NULL == pRoot)
			return bResult;

		queue<TreeNode*> queueTree;
		queueTree.push(pRoot);
		int nCurDepth = 0;
		while (queueTree.size())
		{
			int nQueueSize = queueTree.size();
			vector<int> vecCurLevelNum;
			for (int i = 0; i < nQueueSize; ++i)
			{
				TreeNode* pTreeNode = queueTree.front();
				queueTree.pop();
				if (pTreeNode)
					vecCurLevelNum.push_back(pTreeNode->val);
				else
					vecCurLevelNum.push_back(INVALID_VALUE);

				queueTree.push(pTreeNode ? pTreeNode->left : new TreeNode(INVALID_VALUE));
				queueTree.push(pTreeNode ? pTreeNode->right : new TreeNode(INVALID_VALUE));
			}
			if (IsInValid(vecCurLevelNum))
				return bResult;

			bResult = bResult && bIsSymmetricalLeaf(vecCurLevelNum);
			if (!bResult)
				return false;

			++nCurDepth;
		}
		return bResult;
	}
	bool bIsSymmetricalLeaf(const vector<int> & vecResult)
	{
		bool bIsRetCode = true;
		int nCount = vecResult.size();
		for (int i = 0; i < nCount / 2; ++i)
		{
			bIsRetCode = bIsRetCode && (vecResult[i] == vecResult[nCount - 1 - i]);
		}
		return bIsRetCode;
	}
	bool TestSolution() {
		bool bResult = false;
		
		TreeNode* pNode1 = new TreeNode(5);
		TreeNode* pNode2 = new TreeNode(3);
		TreeNode* pNode3 = new TreeNode(3);
		pNode1->left = pNode2;
		pNode1->right = pNode3;
		
		TreeNode*pNode4 = new TreeNode(4);
		TreeNode*pNode5 = new TreeNode(4);
		pNode2->left = pNode4;
		pNode3->right = pNode5;

		TreeNode* pNode6 = new TreeNode(2);
		TreeNode* pNode7 = new TreeNode(2);
		pNode4->left = pNode6;
		pNode5->right = pNode7;
		pNode7->right = new struct TreeNode(1);
		bool bRetCode = isSymmetrical(pNode1);

		return bResult;
	}
	bool IsInValid(const vector<int> & vecResult)
	{
		bool IsInValid = true;
		for (int i = 0; i < vecResult.size(); ++i)
		{
			IsInValid = IsInValid && (vecResult[i] == INVALID_VALUE);
		}
		return IsInValid;
	}
};