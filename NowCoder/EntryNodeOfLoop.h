#pragma once
//https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

#include <iostream>
#include <map>
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
	ListNode * EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode* pEntryNode = NULL;
		if (NULL == pHead)
			return pHead;

		m_IterRecord.clear();
		ListNode* pCurNode = pHead;
		while (pCurNode)
		{
			if (m_IterRecord.find(pCurNode) == m_IterRecord.end())
			{
				m_IterRecord[pCurNode] = true;
			}
			else
			{
				pEntryNode = pCurNode;
				break;
			}
			pCurNode = pCurNode->next;
		}
		return pEntryNode;
	}
	bool TestSolution() {
		bool bResult = false;
		ListNode* pNode1 = new ListNode(0);
		ListNode* pNode2 = new ListNode(1);
		ListNode* pNode3 = new ListNode(2);
		ListNode* pNode4 = new ListNode(3);
		pNode1->next = pNode2;
		pNode2->next = pNode3;
		pNode3->next = pNode4;
		pNode4->next = NULL;
		ListNode* pRetNode = EntryNodeOfLoop(pNode1);
		bResult = true;
		return bResult;
	}
private:
	std::map<ListNode*, bool> m_IterRecord;
};