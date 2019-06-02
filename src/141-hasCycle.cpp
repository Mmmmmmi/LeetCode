/*
 * 给定一个链表，判断链表中是否有环。

 *
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 * };
 * class Solution {
 *   PUblic:
 *   bool hasCycle(ListNode *head) {
 *   }
 *   };
 *
 *
 *
 *
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        struct ListNode *quick = head;
        struct ListNode *slow = head;
        if (head == NULL) {
            return false;
        }
        while(quick != NULL && quick->next != NULL) {
            quick = quick->next->next;
            slow = slow->next;
            if (quick == slow) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    ListNode l1(3);
    ListNode l2(2);
    ListNode l3(1);
    ListNode l4(4);
    ListNode l5(5);

    return 0;
}

