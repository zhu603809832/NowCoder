#pragma once
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
	void Mirror(TreeNode *pRoot) {
		if (NULL == pRoot)
			return;

		queue<TreeNode*> TraverseTree;
		TraverseTree.push(pRoot);
		while (TraverseTree.size())
		{
			TreeNode* pTopTreeNode = TraverseTree.front();
			TraverseTree.pop();

			TreeNode* pTemp = pTopTreeNode->left;
			pTopTreeNode->left = pTopTreeNode->right;
			pTopTreeNode->right = pTemp;
			if (pTopTreeNode->left)
				TraverseTree.push(pTopTreeNode->left);

			if (pTopTreeNode->right)
				TraverseTree.push(pTopTreeNode->right);
		}
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

		pNode1->left = pNode2;
		pNode1->right = pNode3;
		pNode2->left = pNode4;
		pNode2->right = pNode5;
		pNode3->left = pNode6;
		pNode3->right = pNode7;

		pNode4->left = pNode8;
		Mirror(pNode1);
		bResult = true;
		return bResult;
	}
};