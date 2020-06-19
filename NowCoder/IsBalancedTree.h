#pragma once
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
	bool IsBalanced_Solution(TreeNode* pRoot) {
		bool bResult = true;
		if (NULL == pRoot)
			return true;

		int nLeftDepth = GetTreeDepth(pRoot->left);
		int nRigthDepth = GetTreeDepth(pRoot->right);
		int nDiffDepth = nLeftDepth >= nRigthDepth ? nLeftDepth - nRigthDepth : nRigthDepth - nLeftDepth;
		bResult = (nDiffDepth <= 1);
		bResult = bResult && IsBalanced_Solution(pRoot->left);
		bResult = bResult && IsBalanced_Solution(pRoot->right);

		return bResult;
	}

	int GetTreeDepth(TreeNode* pTreeRoot)
	{
		int nDepth = 0;
		if (NULL == pTreeRoot)
			return nDepth;

		int nLeftDepth = GetTreeDepth(pTreeRoot->left) + 1;
		int nRightDepth = GetTreeDepth(pTreeRoot->right) + 1;
		int nMaxDepth = nLeftDepth >= nRightDepth ? nLeftDepth : nRightDepth;
		return nMaxDepth;
	}
	bool TestSolution() {
		bool bResult = false;
		TreeNode* pNode1 = new TreeNode(1);
		TreeNode* pNode2 = new TreeNode(2);
		TreeNode* pNode3 = new TreeNode(3);
		TreeNode* pNode4 = new TreeNode(4);
		pNode1->left = pNode2;
		pNode1->right = pNode3;
		pNode2->left = pNode4;
		pNode2->right = new struct TreeNode(2);
		pNode4->left = new TreeNode(1);
		pNode3->left = new TreeNode(1);
		int nRetValue  = GetTreeDepth(pNode1);
		bool bRetResult = IsBalanced_Solution(pNode1);
		bResult = true;
		return bResult;
	}
};