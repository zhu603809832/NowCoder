#pragma once
//https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		ListNode* pRetNode = NULL;
		if (NULL == pHead1 || NULL == pHead2)
			return pRetNode;

		int nLenght1 = 0;
		int nLenght2 = 0;
		ListNode* pCurNode1 = pHead1;
		while (pCurNode1)
		{
			++nLenght1;
			pCurNode1 = pCurNode1->next;
		}

		ListNode* pCurNode2 = pHead2;
		while (pCurNode2)
		{
			++nLenght2;
			pCurNode2 = pCurNode2->next;
		}

		ListNode* pLongNode = nLenght1 >= nLenght2 ? pHead1 : pHead2;
		ListNode* pShortNode = nLenght1 < nLenght2 ? pHead1 : pHead2;
		int nDiffNum = nLenght1 >= nLenght2 ? nLenght1 - nLenght2 : nLenght2 - nLenght1;
		while (nDiffNum)
		{
			--nDiffNum;
			pLongNode = pLongNode->next;
		}
		while (pLongNode && pShortNode)
		{
			if (pLongNode == pShortNode)
			{
				pRetNode = pLongNode;
				break;
			}
			pLongNode = pLongNode->next;
			pShortNode = pShortNode->next;
		}
		return pRetNode;
	}
	bool TestSolution() {
		ListNode* pNode1 = new ListNode(0);
		ListNode* pNode2 = new ListNode(1);
		ListNode* pNode3 = new ListNode(2);
		ListNode* pNode4 = new ListNode(3);
		pNode1->next = pNode2;
		pNode2->next = pNode3;
		pNode3->next = pNode4;

		ListNode* pNode11 = new ListNode(0);
		ListNode* pNode22 = new ListNode(1);
		ListNode* pNode33 = new ListNode(2);
		ListNode* pNode44 = new ListNode(3);
		pNode11->next = pNode22;
		pNode22->next = pNode33;
		pNode33->next = pNode3;
		ListNode* pRetNode = FindFirstCommonNode(pNode1, pNode1);
		return true;
	}
};