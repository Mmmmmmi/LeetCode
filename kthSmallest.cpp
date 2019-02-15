/*
 *
 *
 * 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
 * 说明：
 * 你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
 *
 *  示例 1:
 *   
 * 输入: root = [3,1,4,null,2], k = 1
 *    3
 *   / \
 *  1   4
 *   \
 *    2
 * 输出: 1
 * 示例 2:
 * 
 * 输入: root = [5,3,6,2,4,null,null,1], k = 3
 *        5
 *       / \
 *      3   6
 *     / \
 *    2   4
 *   /
 *  1
 * 输出: 3
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * class Solution {
 * public:
 *   int kthSmallest(TreeNode* root, int k) {
 *   }
 *};
 *
 */


#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) {
            return 0;
        }
        _index = k;
        _k = 0;
        _ret = 0;
        _flag = 0;
        inorder(root);
        return _ret;
    }
private:
    void inorder(TreeNode* root)
    {
        if (root == NULL) {
            return;
        }
        cout << root->val << endl;
        inorder(root->left);
        if (_flag == 0 &&root->left == NULL) {
            _k = 1;
            _flag = 1;
        }else {
            _k++;
        }
        if (_k == _index) {
            _ret = root->val;
            return;
        }
        inorder(root->right);
    }
    int _k;
    int _ret;
    int _index;
    int _flag = 0;
};


int main()
{
    TreeNode t1(5);
    TreeNode t2(3);
    TreeNode t3(6);
    TreeNode t4(2);
    TreeNode t5(4);
    TreeNode t6(1);
    Solution s;
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t4.left = &t6;
    cout << s.kthSmallest(&t1, 1) << endl;
    return 0;
}

