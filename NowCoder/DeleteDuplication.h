#pragma once
//https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <iostream>
#include <set>

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
	ListNode * deleteDuplication(ListNode* pHead)
	{
		m_setNodeToBeRemoved.clear();
		ListNode* pNewHead = NULL;
		if (NULL == pHead)
			return pNewHead;

		ListNode* pCurNode = pHead;
		while (pCurNode)//Record to be Removed Node
		{
			ListNode* pNextNode = pCurNode->next;
			if (pNextNode && pNextNode->val == pCurNode->val)
			{
				m_setNodeToBeRemoved.insert(pCurNode);
				m_setNodeToBeRemoved.insert(pNextNode);
			}
			pCurNode = pCurNode->next;
		}

		ListNode* pNewCurNode = NULL;
		pCurNode = pHead;
		while (pCurNode)
		{
			if (m_setNodeToBeRemoved.find(pCurNode) == m_setNodeToBeRemoved.end())
			{
				if (NULL == pNewHead)
				{
					pNewHead = pCurNode;
					pNewCurNode = pCurNode;
				}
				
				ListNode* pBackUpNextNode = pCurNode->next;
				if (pNewCurNode)
				{
					pNewCurNode->next = pCurNode;
					pCurNode->next = NULL;
					pNewCurNode = pCurNode;
				}
				pCurNode = pBackUpNextNode;
				continue;
			}

			pCurNode = pCurNode->next;
		}
		return pNewHead;
	}
	bool TestSolution()
	{
		ListNode* pNode1 = new ListNode(1);
		ListNode* pNode2 = new ListNode(1);
		ListNode* pNode3 = new ListNode(1);
		ListNode* pNode4 = new ListNode(1);
		pNode1->next = pNode2;
		pNode2->next = pNode3;
		pNode3->next = pNode4;
		ListNode* pRetNode = deleteDuplication(pNode1);
		return true;
	}
private:
	std::set<ListNode*>	m_setNodeToBeRemoved;
};