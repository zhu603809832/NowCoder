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
�����Ҫ��������ڵ�ָ���������е������
1.�ھ������ܴ�����������ʱ�����������������ڵ�
2.���ݾ����������ڵ㣬��ʼ����������ֵܽڵ�
3.�Ӿ������в�ִ��µ�����
*/