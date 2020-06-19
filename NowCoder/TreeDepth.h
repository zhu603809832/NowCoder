#pragma once
//https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=11191&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
	int TreeDepth(TreeNode* pRoot)
	{
		int nDepth = 0;
		if (NULL == pRoot)
			return nDepth;

		int nLeftDepth = TreeDepth(pRoot->left) + 1;
		int nRigthDepth = TreeDepth(pRoot->right) + 1;
		nDepth = nLeftDepth >= nRigthDepth ? nLeftDepth : nRigthDepth;
		return nDepth;
	}
	bool TestSolution()
	{
		TreeNode* pNode1 = new TreeNode(1);
		TreeNode* pNode2 = new TreeNode(2);
		TreeNode* pNode3 = new TreeNode(3);
		TreeNode* pNode4 = new TreeNode(4);
		TreeNode* pNode5 = new TreeNode(5);
		TreeNode* pNode6 = new TreeNode(6);
		pNode1->left = pNode2;
		pNode1->right = pNode3;

		pNode2->left = pNode4;
		pNode4->left = pNode5;
		pNode5->right = pNode6;
		int nDepth = TreeDepth(pNode1);
		return nDepth;
	}
};
/*
链接：https://www.nowcoder.com/questionTerminal/435fb86331474282a3499955f0a41e8b?f=discussion
来源：牛客网
//Java BFS
import java.util.Queue;
import java.util.LinkedList;

public class Solution {
public int TreeDepth(TreeNode pRoot)
{
if(pRoot == null){
return 0;
}
Queue<TreeNode> queue = new LinkedList<TreeNode>();
queue.add(pRoot);
int depth = 0, count = 0, nextCount = 1;
while(queue.size()!=0){
TreeNode top = queue.poll();
count++;
if(top.left != null){
queue.add(top.left);
}
if(top.right != null){
queue.add(top.right);
}
if(count == nextCount){
nextCount = queue.size();
count = 0;
depth++;
}
}
return depth;
}
}
*/