/*
 *  给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 *
 *  为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
 *
 *  说明：不允许修改给定的链表。
 *
 *
 *
 *  Definition for singly-linked list.
 *  struct ListNode {
 *  int val;
 *  ListNode *next;
 *  ListNode(int x) : val(x), next(NULL) {}
 *  };
 *  
 * class Solution {
 *  public:
 *  ListNode *detectCycle(ListNode *head) {
 *  }
 *   };
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = NULL;
        ListNode *slow = NULL;
        if (head == NULL) {
            return NULL;
        }
        fast = head;
        slow = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                fast = head;
                while(fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
    
};

int main()
{
    ListNode l1(0);
    ListNode l2(1);
    ListNode l3(2);
    ListNode l4(3);
    ListNode l5(4);
    Solution s;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l3;
    cout << s.detectCycle(&l1)->val << endl;
    return 0;
}

