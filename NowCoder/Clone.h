#pragma once
#define NULL 0
#include <map>
#include <vector>
//Failed!!
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
using namespace std;
class Solution {
public:
	RandomListNode * Clone(RandomListNode* pHead)
	{
		std::map<RandomListNode*, int> mapNodePos;
		std::vector<RandomListNode*> vecNode;
		RandomListNode * pRetNode = NULL;
		if (NULL == pHead)
			return NULL;
		
		int nIndex = 0;
		RandomListNode* pCurNode = pHead;
		RandomListNode* pNewCurNode = pRetNode;
		while (pCurNode)
		{
			vecNode.push_back(pCurNode);
			mapNodePos[pCurNode] = nIndex;

			RandomListNode* pNewNode = new RandomListNode(pCurNode->label);
			if (pNewCurNode)
				pNewCurNode->next = pNewNode;

			pNewCurNode = pNewNode;
			if (NULL == pRetNode)
				pRetNode = pNewCurNode;

			pCurNode = pCurNode->next;
			++nIndex;
		}

		pNewCurNode = pRetNode;
		pCurNode = pHead;
		while (pCurNode)
		{
			RandomListNode* pRandom = pCurNode->random;
			int nPos = mapNodePos[pRandom];
			pNewCurNode->random = vecNode[nPos];
			pNewCurNode = pNewCurNode->next;
			pCurNode = pCurNode->next;
		}
		return pRetNode;
	}

	bool TestSolution() {
		RandomListNode* pNode1 = new RandomListNode(1);
		RandomListNode* pNode2 = new RandomListNode(2);
		RandomListNode* pNode3 = new RandomListNode(3);
		RandomListNode* pNode4 = new RandomListNode(4);
		RandomListNode* pNode5 = new RandomListNode(5);
		RandomListNode* pNode6 = new RandomListNode(3);
		RandomListNode* pNode7 = new RandomListNode(5);
		pNode1->next = pNode2; pNode1->random = pNode4;
		pNode2->next = pNode3; pNode2->random = pNode7;
		pNode3->next = pNode4; pNode3->random = NULL;
		pNode4->next = pNode5; pNode4->random = pNode1;
		RandomListNode* pRetNode = Clone(pNode1);
		return true;
	}
};
/*
https://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba?answerType=1&f=discussion
解答（需要考虑随机节点指向不在链表中的情况）
1.在旧链表总创建新链表，此时不处理新链表的随机节点
2.根据旧链表的随机节点，初始化新链表的兄弟节点
3.从旧链表中拆分处新的链表
*/