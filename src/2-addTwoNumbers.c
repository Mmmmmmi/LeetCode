/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807

Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    }
};
*/


#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
#if 0
    struct ListNode *cur1 = NULL;
    struct ListNode *cur2 = NULL;
    struct ListNode *newcur = NULL;
    struct ListNode *ret = NULL;
    struct ListNode *tmp = NULL;
    int cf = 0;
    cur1 = l1;
    if(l1 == NULL || l2 == NULL) {
        return NULL;
    }
    cur1 = l1;
    cur2 = l2;
    while(cur1 != NULL && cur2 != NULL) {
        tmp = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (tmp == NULL) {
            return NULL;
        }
        tmp->val = cur1->val + cur2->val + cf;
        tmp->next = NULL;
        if (tmp->val / 10 >= 1) {
            cf = 1;
        }
        else {
            cf = 0;
        }
        tmp->val %= 10;
        if (ret == NULL) {
            tmp->next = ret;
            ret = tmp;
            newcur = tmp;
        }
        else {
            newcur->next = tmp;
            newcur = tmp;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    struct ListNode *cur = cur1;
    if (cur1 == NULL) {
        cur = cur2;
    }
    while(cur != NULL) {
        tmp = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (tmp == NULL) {
            return NULL;
        }
        tmp->val = cur->val + cf;
        tmp->next = NULL;
        if (tmp->val / 10 >= 1) {
            cf = 1;
        }
        else {
            cf = 0;
        }
        tmp->val %= 10;
        newcur->next = tmp;
        newcur = tmp;
        cur = cur->next;
    }
    if (cf == 1) {
        tmp = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (tmp == NULL) {
            return NULL;
        }
        tmp->val = cf;
        tmp->next = NULL;
        newcur->next = tmp;
    }
    return ret;
#else 
    struct ListNode *ret = NULL;
    struct ListNode *newcur = NULL;
    int cf = 0;
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }
    while (l1 != NULL || l2 != NULL) {
        int val1 = l1 != NULL ? l1->val : 0;
        int val2 = l2 != NULL ? l2->val : 0;
        struct ListNode *tmp = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (tmp == NULL) {
            return NULL;
        }
        tmp->val = val1 + val2 + cf;
        tmp->next = NULL;
        if (tmp->val / 10 >= 1) {
            cf = 1;
        }
        else cf = 0;
        tmp->val %= 10;
        if (ret == NULL) {
            ret = tmp;
            newcur = tmp;
        }
        else {
            newcur->next = tmp;
            newcur = tmp;
        }
        l1 = l1 != NULL ? l1->next : NULL;
        l2 = l2 != NULL ? l2->next : NULL;
    }
    if (cf == 1) {
        struct ListNode *tmp = (struct ListNode *) malloc (sizeof(struct ListNode));
        if (tmp == NULL) {
            return NULL;
        }
        tmp->val = cf;
        tmp->next = NULL;
        newcur->next = tmp;
    }
    return ret;


#endif 


}

int main()
{
    struct ListNode a = {2,NULL};
    struct ListNode b = {4,&a};
    struct ListNode c = {3,&b};
    struct ListNode d = {5,NULL};
    struct ListNode e = {6,&d};
    struct ListNode f = {4,&e};
    struct ListNode *r = addTwoNumbers(&c,&f);
    while (r != NULL) {
        printf("%d", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;

}
