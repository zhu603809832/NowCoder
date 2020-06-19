#pragma once
//https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> vecResult;
		queue<TreeNode*> queueIter;
		if (NULL == root)
			return vecResult;

		queueIter.push(root);
		while (0 != queueIter.size())
		{
			TreeNode* pCurNode = queueIter.front();
			queueIter.pop();
			vecResult.push_back(pCurNode->val);
			if (pCurNode->left)
			{
				queueIter.push(pCurNode->left);
			}
			if (pCurNode->right)
			{
				queueIter.push(pCurNode->right);
			}
		}
		return vecResult;
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

		pNode4->left = pNode6;
		vector<int> vec = PrintFromTopToBottom(pNode1);
		bResult = true;
		return bResult;
	}
};
