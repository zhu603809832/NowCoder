#pragma once
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
	ListNode * ReverseList(ListNode* pHead) {
		ListNode* pRetNewHead = NULL;
		if (NULL == pHead)
		{
			return pRetNewHead;
		}
		ListNode* pNode = pHead;
		ListNode* pNewCurNode = NULL;
		while (pNode)
		{
			ListNode* pBackupNextNode = pNode->next;

			pNode->next = pNewCurNode;
			pNewCurNode = pNode;

			pNode = pBackupNextNode;
		}
		pRetNewHead = pNewCurNode;
		return pRetNewHead;
	}
	bool TestSolution() {
		bool bResult = false;
		ListNode* pNode1 = new ListNode(1);
		ListNode* pNode2 = new ListNode(2);
		ListNode* pNode3 = new ListNode(3);
		pNode1->next = pNode2;
		pNode2->next = pNode3;
		ListNode* pRet = ReverseList(pNode1);
		bResult = true;
		return bResult;
	}
};