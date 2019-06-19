/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明 :
你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {

	}
};
*/


#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
	void reverseList(ListNode*& head, ListNode*& tail)
	{
		ListNode* prev = nullptr;
		ListNode* cur = head;
		ListNode* next = head->next;
		while (prev != tail)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		swap(head, tail);
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* left = head;
		ListNode* right = head;
		int n = k;
		ListNode* prev = nullptr;
		ListNode* next;
		while (right != nullptr)
		{
			n--;
			right = right->next;
			if (n == 1 && right != nullptr)
			{
				n = k;
				ListNode* next = right->next;
				if (prev == nullptr)
				{
					reverseList(head, right);
				}
				else
				{
					reverseList(prev->next, right);
				}
				prev = right;
				right->next = next;
				right = next;
			}
		}
		return head;
	}
};

int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);
	ListNode* l6 = new ListNode(6);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	Solution s;
	//s.reverseList(l1, l5);
	ListNode* cur = s.reverseKGroup(l1, 2);
	while (cur != nullptr)
	{
		cout << cur->val << endl;
		cur = cur->next;
	}
	return 0;
}
