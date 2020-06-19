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
	ListNode * FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* pRetNode = NULL;
		int nLength = 0;
		ListNode* pNode = pListHead;
		while (pNode)
		{
			++nLength;
			pNode = pNode->next;
		}

		int nOffset = nLength - k;
		pRetNode = pListHead;
		while (nOffset && pRetNode)
		{
			--nOffset;
			pRetNode = pRetNode->next;
		}
		return pRetNode;
	}
	bool TestSolution() {
		bool bResult = false;
		ListNode* pNode1 = new ListNode(1);
		ListNode* pNode2 = new ListNode(2);
		ListNode* pNode3 = new ListNode(3);
		pNode1->next = pNode2;
		pNode2->next = pNode3;
		ListNode* pNodeRet = FindKthToTail(pNode1, 4);

		bResult = true;
		return bResult;
	}
};
/*
���ӣ�https://www.nowcoder.com/questionTerminal/529d3ae5a407492994ad2a246518148a?f=discussion
��Դ��ţ����

class Solution:
def FindKthToTail(self, head, k):
# write code here
if head==None or k<=0:
return None
#��������ָ�룬p2ָ�����ߣ�k-1������Ȼ����һ���ߣ���p2Ϊ���һ��ʱ��p1��Ϊ������k�� ��
p2=head
p1=head
#p2���ߣ���k-1�������k�����������򷵻� �գ�����Ļ�������
while k>1:
if p2.next!=None:
p2=p2.next
k-=1
else:
return None
#����ָ��һ�� �ߣ�һֱ��p2Ϊ���һ��,p1��Ϊ����
while p2.next!=None:
p1=p1.next
p2=p2.next
return p1
*/