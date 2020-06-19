#pragma once
//https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* pRetNewHead = NULL;
		if (NULL == pHead1)
			return pHead2;

		if (NULL == pHead2)
			return pHead1;

		ListNode* pCurNewNode = NULL;
		ListNode* pCurNode1 = pHead1;
		ListNode* pCurNode2 = pHead2;
		while (pCurNode1 && pCurNode2)
		{
			if (pCurNode1->val < pCurNode2->val)
			{
				ListNode* pNextNode = pCurNode1->next;
				if (pCurNewNode)
				{
					pCurNewNode->next = pCurNode1;
				}
				pCurNewNode = pCurNode1;
				pCurNewNode->next = NULL;
				pCurNode1 = pNextNode;
			}
			else
			{
				ListNode* pNextNode = pCurNode2->next;
				if (pCurNewNode)
				{
					pCurNewNode->next = pCurNode2;
				}
				pCurNewNode = pCurNode2;
				pCurNewNode->next = NULL;
				pCurNode2 = pNextNode;
			}
			if (NULL == pRetNewHead)
				pRetNewHead = pCurNewNode;
		}
		if (NULL == pCurNode1)
			pCurNewNode->next = pCurNode2;

		if (NULL == pCurNode2)
			pCurNewNode->next = pCurNode1;

		return pRetNewHead;
	}
	bool TestSolution() {
		ListNode* pNode1 = new ListNode(0);
		ListNode* pNode2 = new ListNode(2);
		ListNode* pNode3 = new ListNode(7);
		ListNode* pNode4 = new ListNode(9);
		pNode1->next = pNode2;
		pNode2->next = pNode3;
		pNode3->next = pNode4;

		ListNode* pNode11 = new ListNode(2);
		ListNode* pNode22 = new ListNode(5);
		ListNode* pNode33 = new ListNode(6);
		ListNode* pNode44 = new ListNode(10);
		pNode11->next = pNode22;
		pNode22->next = pNode33;
		pNode33->next = pNode44;
		ListNode* pRetNode = Merge(pNode1, pNode11);
		return true;
	}
};

/*
链接：https://www.nowcoder.com/questionTerminal/d8b6b4358f774294a89de2a6ac4d9337?f=discussion
来源：牛客网

public class Solution {
	public ListNode Merge(ListNode list1,ListNode list2) {
		//新建一个头节点，用来存合并的链表。
		ListNode head=new ListNode(-1);
		head.next=null;
		ListNode root=head;
		while(list1!=null&&list2!=null){
			if(list1.val<list2.val){
				head.next=list1;
				head=list1;
				list1=list1.next;
			}else{
				head.next=list2;
				head=list2;
				list2=list2.next;
			}
		}
		//把未结束的链表连接到合并后的链表尾部
		if(list1!=null){
			head.next=list1;
		}
		if(list2!=null){
			head.next=list2;
		}
		return root.next;
	}
}
*/