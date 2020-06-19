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

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > vecRetValue;
		if (NULL == pRoot)
			return vecRetValue;

		queue<TreeNode*> queueIterTreeNode;
		queue<int> queueTreeNodeDepth;
		queueIterTreeNode.push(pRoot);
		queueTreeNodeDepth.push(0);
		
		while (queueIterTreeNode.size())
		{
			TreeNode* pFontTreeNode = queueIterTreeNode.front();
			int nCurDepth = queueTreeNodeDepth.front();
			queueIterTreeNode.pop();
			queueTreeNodeDepth.pop();
			if (nCurDepth >= vecRetValue.size())
			{
				vector<int> vecTemp;
				vecTemp.push_back(pFontTreeNode->val);
				vecRetValue.push_back(vecTemp);
			}
			else
				vecRetValue[nCurDepth].push_back(pFontTreeNode->val);

			if (pFontTreeNode->left)
			{
				queueIterTreeNode.push(pFontTreeNode->left);
				queueTreeNodeDepth.push(nCurDepth + 1);
			}

			if (pFontTreeNode->right)
			{
				queueIterTreeNode.push(pFontTreeNode->right);
				queueTreeNodeDepth.push(nCurDepth + 1);
			}
		}
		return vecRetValue;
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