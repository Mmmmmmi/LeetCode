/*
 * 编写一个程序，找到两个单链表相交的起始节点。
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * class Solution {
 * public:
 *    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
 *
 *    }
 * };
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = NULL;
        ListNode *curB = NULL;
        int nodenumA = 0;
        int nodenumB = 0;
        //有一个为空
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        //直接相交
        if (headA == headB) {
            return headA;
        }
        //求出两个链表的长度 可能是带环的
        curA = headA;
        curB = headB;
        while(curA) {
            curA = curA->next;
            nodenumA++;
        }
        while(curB) {
            curB = curB->next;
            nodenumB++;
        }
        cout << nodenumA << "  " << nodenumB << endl;
        //使两个链表长度相同
        curA = headA;
        curB = headB;
        while(nodenumA > nodenumB) { 
            curA = curA->next;
            nodenumA--;
        }
        while(nodenumB > nodenumA) { 
            curB = curB->next;
            nodenumB--;
        }
        cout << nodenumA << "  " << nodenumB << endl;
        while (curA && curB) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;*/
    }
};

int main()
{
    ListNode L1(4);
    ListNode L2(1);
    ListNode L3(8);
    ListNode L4(4);
    ListNode L5(5);
    ListNode L6(5);
    ListNode L7(0);
    ListNode L8(1);
    ListNode L9(9);
    L1.next = &L2;
    L2.next = &L3;
    L3.next = &L4;
    L4.next = &L5;
    L6.next = &L7;
    L7.next = &L8;
    L8.next = &L3;
    Solution s;
    cout << s.getIntersectionNode(&L1, &L6) << endl;
    return 0;
}

