/*
 * 给定一个二叉树，找出其最大深度。
 *
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 * 示例： 
 *           3 
 *          /  \
 *         9    20
 *              / \
 *             15  7
 *  返回3
 *  
 *    Definition for a binary tree node.
 *    struct TreeNode {
 *        int val;
 *        TreeNode *left;
 *        TreeNode *right;
 *        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *    };
 *    
 *  class Solution {
 *  public:
 *    int maxDepth(TreeNode* root) {
 *    }
 *  };
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
    int maxDepth(TreeNode* root) {
        //如果节点为空，说明深度为0
        if (root == NULL) {
            return 0;
        } 
        int depthleft = maxDepth(root->left);
        int depthright = maxDepth(root->right);
        //返回左右节点中大的 并且加上自己
        return ( depthleft > depthright ? depthleft : depthright ) + 1;
    }

};

int main()
{
    TreeNode A(3);
    TreeNode B(9);
    TreeNode C(20);
    TreeNode D(15);
    TreeNode E(7);
    A.left = &B;
    A.right = &C;
    C.left = &D;
    C.right = &E;
    Solution s;
    cout << "Depth = " << s.maxDepth(&A) << endl;
    return 0;
}
