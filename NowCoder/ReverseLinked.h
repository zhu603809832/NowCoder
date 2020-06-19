#pragma once
//https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

#include <vector>
using namespace std;

#define NULL 0

struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> vRetResult;
		if (NULL == head)
			return vRetResult;

		ListNode* pReversedHeadNode = NULL;
		ListNode* pCurNode = head;
		while (pCurNode)
		{
			ListNode* pNextNode = pCurNode->next;
			pCurNode->next = pReversedHeadNode;
			pReversedHeadNode = pCurNode;
			pCurNode = pNextNode;
		}
		pCurNode = pReversedHeadNode;
		while (pCurNode)
		{
			vRetResult.push_back(pCurNode->val);
			pCurNode = pCurNode->next;
		}
		return vRetResult;
	}
	bool TestSolution() {
		bool bResult = false;
		ListNode* pNode1 = new ListNode(0);
		ListNode* pNode2 = new ListNode(1);
		ListNode* pNode3 = new ListNode(2);
		pNode1->next = pNode2;
		pNode2->next = pNode3;
		vector<int> vRetValue = printListFromTailToHead(pNode1);

		bResult = true;
		return bResult;
	}
};