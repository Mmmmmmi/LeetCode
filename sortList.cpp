/*
 *
 *
 * (n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 *示例 1:
 * 输入: 4->2->1->3
 *输出: 1->2->3->4
 *示例 2:

 *输入: -1->5->3->4->0
 *输出: -1->0->3->4->5
 *
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode *next;
 *ListNode(int x) : val(x), next(NULL) {}
 *};
 *class Solution {
 *public:
 *    ListNode* sortList(ListNode* head) {
 *    }
 *};
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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        sort(head, NULL);
        return head;
    }
private:
    void sort(ListNode *head, ListNode *end)
    {
        struct ListNode *fast = NULL;
        struct ListNode *slow = NULL;
        if(head == end || head->next == end) {
            return;
        }
        fast = head;
        slow = head;
        while(fast && fast->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        sort(head, slow);
        //走到这里 说明 fast 走到最后 slow 走到一半
        sort(slow, end);

        merge(head, slow, slow, end);
    }
    
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* ret = NULL;
    struct ListNode* cur1 = NULL;
    struct ListNode* cur2 = NULL;
    struct ListNode* curret = NULL;
    if (l1 == NULL) {
        return l2;
    }  
    if (l2 == NULL) {
        return l1;
    }
    cur1 = l1;
    cur2 = l2;
    while(cur1 != NULL && cur2 != NULL) {
        if (cur1->val <= cur2->val) {
            if (ret == NULL) {
                ret = cur1;
            }
            else {
                curret->next = cur1;
            }
            curret = cur1;
            cur1 = cur1->next;
        }else {
            if (ret == NULL) {
                ret = cur2;
            }
            else {
                curret->next = cur2;
            }
            curret = cur2;
            cur2 = cur2->next;
        }
        
    }
    curret->next = cur1 == NULL ? cur2 : cur1;
    return ret;
}

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

