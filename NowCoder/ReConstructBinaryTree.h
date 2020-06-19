#pragma once

#include <vector>
using namespace std;
//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> vecPreOrder, vector<int> vecInOrder) {
		TreeNode* pqRootNode = NULL;
		int nPreOrderNum = vecPreOrder.size();
		int nInOderNum = vecInOrder.size();
		if (0 == nPreOrderNum || 0 == nInOderNum)
			return pqRootNode;

		pqRootNode = ConstructBinaryTree(NULL, vecPreOrder, vecInOrder);
		return pqRootNode;
	}

	TreeNode* ConstructBinaryTree(TreeNode* pqCurRoot, vector<int> vecPreOrder, vector<int> vecInOrder)
	{
		TreeNode* pqRetTreeNode = NULL;
		int nPreOrderNum = vecPreOrder.size();
		int nInOderNum = vecInOrder.size();
		if (0 == nPreOrderNum || 0 == nInOderNum)
			return pqRetTreeNode;

		int nRootValue = vecPreOrder[0];
		TreeNode* pqRootNode = new TreeNode(nRootValue);
		int nInOrderIndex = GetIndexInVec(vecInOrder, nRootValue);
		vector<int> vecTempLeftPreOrder;
		vector<int> vecTempLeftInOrder;

		vector<int> vecTempRightPreOrder;
		vector<int> vecTempRightInOrder;

		for (int i = 0; i < nInOrderIndex; ++i)
		{
			int nInOrderValue = vecInOrder[i];
			vecTempLeftInOrder.push_back(nInOrderValue);
		}

		for (int i = 0;  i < nPreOrderNum; ++i)
		{
			int nPreOrderValue = vecPreOrder[i];
			int nIndexInPreOrder = GetIndexInVec(vecTempLeftInOrder, nPreOrderValue);
			if (nIndexInPreOrder >= 0)
				vecTempLeftPreOrder.push_back(nPreOrderValue);
		}

		for (int i = nInOrderIndex + 1; i < nInOderNum; ++i)
		{
			int nInOrderValue = vecInOrder[i];
			vecTempRightInOrder.push_back(nInOrderValue);
		}

		for (int i = 0; i < nPreOrderNum; ++i)
		{
			int nPreOrderValue = vecPreOrder[i];
			int nIndexInPreOrder = GetIndexInVec(vecTempRightInOrder, nPreOrderValue);
			if (nIndexInPreOrder >= 0)
				vecTempRightPreOrder.push_back(nPreOrderValue);
		}

		pqRootNode->left = ConstructBinaryTree(pqCurRoot, vecTempLeftPreOrder, vecTempLeftInOrder);
		pqRootNode->right = ConstructBinaryTree(pqCurRoot, vecTempRightPreOrder, vecTempRightInOrder);
		pqRetTreeNode = pqRootNode;
		return pqRetTreeNode;
	}

	int GetIndexInVec(vector<int> vecTraverseOrder, int nValue)
	{
		int nIndex = -1;
		for (int i = 0; i < vecTraverseOrder.size(); ++i)
		{
			int nTempValue = vecTraverseOrder[i];
			if (nTempValue == nValue)
			{
				return i;
			}
		}
		return nIndex;
	}
	bool TestSolution() {
		bool bResult = false;
		int nPreOrder[] = { 1,2,4,7,3,5,6,8 };
		int nInOrder[] = { 4,7,2,1,5,3,8,6  };
		vector<int> vecPreOrder(nPreOrder, nPreOrder + 8);
		vector<int> vecInOrder(nInOrder, nInOrder + 8);
		TreeNode* pRetRoot = reConstructBinaryTree(vecPreOrder, vecInOrder);
		bResult = true;
		return bResult;
	}
};


/*
链接：https://www.nowcoder.com/questionTerminal/8a19cbe657394eeaac2f6ea9b0f6fcf6?f=discussion
来源：牛客网

public class Solution {
public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
TreeNode root=reConstructBinaryTree(pre,0,pre.length-1,in,0,in.length-1);
return root;
}
//前序遍历{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
private TreeNode reConstructBinaryTree(int [] pre,int startPre,int endPre,int [] in,int startIn,int endIn) {

if(startPre>endPre||startIn>endIn)
return null;
TreeNode root=new TreeNode(pre[startPre]);

for(int i=startIn;i<=endIn;i++)
if(in[i]==pre[startPre]){
root.left=reConstructBinaryTree(pre,startPre+1,startPre+i-startIn,in,startIn,i-1);
root.right=reConstructBinaryTree(pre,i-startIn+startPre+1,endPre,in,i+1,endIn);
break;
}

return root;
}
}

*/