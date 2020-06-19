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
链接：https://www.nowcoder.com/questionTerminal/529d3ae5a407492994ad2a246518148a?f=discussion
来源：牛客网

class Solution:
def FindKthToTail(self, head, k):
# write code here
if head==None or k<=0:
return None
#设置两个指针，p2指针先走（k-1）步，然后再一起走，当p2为最后一个时，p1就为倒数第k个 数
p2=head
p1=head
#p2先走，走k-1步，如果k大于链表长度则返回 空，否则的话继续走
while k>1:
if p2.next!=None:
p2=p2.next
k-=1
else:
return None
#两个指针一起 走，一直到p2为最后一个,p1即为所求
while p2.next!=None:
p1=p1.next
p2=p2.next
return p1
*/