#pragma once
#define NULL 0
#include <vector>
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
	bool HasSubtree(TreeNode* pRootA, TreeNode* pRootB)
	{
		bool bHasSubTree = false;
		if (NULL == pRootA || NULL == pRootB)
			return bHasSubTree;

		bHasSubTree = TraversalTree(pRootA, pRootB);
		return bHasSubTree;
	}
	
	bool TraversalTree(TreeNode* pTreeA, TreeNode* pTreeRootB) {
		bool bIsSubTree = false;
		if (pTreeA && pTreeRootB)
		{
			int nValueA = pTreeA->val;
			int nValueB = pTreeRootB->val;
			if (nValueA == nValueB)
				bIsSubTree = IsSubTree(pTreeA, pTreeRootB);
		}
		bIsSubTree = bIsSubTree || IsSubTree(pTreeA->left, pTreeRootB);
		bIsSubTree = bIsSubTree || IsSubTree(pTreeA->right, pTreeRootB);
		return bIsSubTree;
	}
	void PreorderTraversalTree(TreeNode* pParent, vector<int>& vec)
	{
		if (NULL == pParent)
			return;

		vec.push_back(pParent->val);
		PreorderTraversalTree(pParent->left, vec);
		PreorderTraversalTree(pParent->right, vec);
		return;
	}

	void MidorderTraversalTree(TreeNode* pParent, vector<int>& vec)
	{
		if (NULL == pParent)
			return;

		MidorderTraversalTree(pParent->left, vec);
		vec.push_back(pParent->val);
		MidorderTraversalTree(pParent->right, vec);
		return;
	}

	void PostorderTraversalTree(TreeNode* pParent, vector<int>& vec)
	{
		if (NULL == pParent)
			return;

		PostorderTraversalTree(pParent->left, vec);
		PostorderTraversalTree(pParent->right, vec);
		vec.push_back(pParent->val);
		return;
	}

	bool IsSubTree(TreeNode* pTreeA, TreeNode* pTreeB)
	{
		bool bIsSubTree = false;
		if (NULL == pTreeA && NULL == pTreeB)
			return true;

		if (pTreeB)
		{
			if (NULL == pTreeA)
				return false;

			bIsSubTree = pTreeA->val == pTreeB->val;
			if (pTreeB->left)
				bIsSubTree = bIsSubTree && IsSubTree(pTreeA->left, pTreeB->left);

			if (pTreeB->right)
				bIsSubTree = bIsSubTree && IsSubTree(pTreeA->right, pTreeB->right);
		}

		return bIsSubTree;
	}
	bool TestSolution() {
		bool bResult = false;
		TreeNode* pNode1 = new TreeNode(1);
		TreeNode* pNode2 = new TreeNode(2);
		TreeNode* pNode3 = new TreeNode(3);
		TreeNode* pNode4 = new TreeNode(4);
		TreeNode* pNode5 = new TreeNode(5);
		TreeNode* pNode6 = new TreeNode(6);
		pNode1->left = pNode2;
		pNode1->right = pNode3;
		pNode2->left = pNode4;
		pNode2->right = pNode5;
		pNode3->left = pNode6;
		/*std::vector<int> PreTraverseVec;
		PreorderTraversalTree(pNode1, PreTraverseVec);

		std::vector<int> MiTraverseVec;
		MidorderTraversalTree(pNode1, MiTraverseVec);

		std::vector<int> PostTraverseVec;
		PostorderTraversalTree(pNode1, PostTraverseVec);*/

		TreeNode* pNodeA = new TreeNode(3);
		TreeNode* pNodeB = new TreeNode(4);
		TreeNode* pNodeC = new TreeNode(6);
		pNodeA->left = pNodeC;
		/*pNodeA->right = pNodeC;*/

		bool bIsCan = HasSubtree(pNode1, pNodeA);
		bResult = true;
		return bResult;
	}
};