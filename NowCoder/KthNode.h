#pragma once
#define NULL 0
#include <vector>

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
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		TreeNode* pRetTreeNode = NULL;
		if (NULL == pRoot || 0 == k)
			return NULL;

		std::vector<TreeNode* > vecTraverseTree;
		MidOrderTraverseTree(pRoot, vecTraverseTree);
		if (k - 1 < vecTraverseTree.size())
			pRetTreeNode = vecTraverseTree[k - 1];

		return pRetTreeNode;
	}
	void MidOrderTraverseTree(TreeNode* pParentTree, std::vector<TreeNode* >& vecTree)
	{
		if (NULL == pParentTree)
			return;

		MidOrderTraverseTree(pParentTree->left, vecTree);
		vecTree.push_back(pParentTree);
		MidOrderTraverseTree(pParentTree->right, vecTree);
		return;
	}


	bool TestSolution()
	{
		bool bResult = false;
		TreeNode* pNode1 = new TreeNode(5);
		TreeNode* pNode2 = new TreeNode(3);
		TreeNode* pNode3 = new TreeNode(7);
		TreeNode* pNode4 = new TreeNode(2);
		TreeNode* pNode5 = new TreeNode(4);
		TreeNode* pNode6 = new TreeNode(6);
		TreeNode* pNode7 = new TreeNode(8);

		pNode1->left = pNode2;
		pNode1->right = pNode3;

		/*pNode2->left = pNode4;
		pNode2->right = pNode5;

		pNode3->left = pNode6;
		pNode3->right = pNode7*/;
		
		TreeNode* pRet = KthNode(pNode1, 3);

		bResult = true;
		return bResult;
	}

};