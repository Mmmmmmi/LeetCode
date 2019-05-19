/*
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 * class Solution {
 * public:
 *     int findKthLargest(vector<int>& nums, int k) {
 *             
 *                 }
 *                 };
 *     }
 * }
 */
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //用堆排序的方法
        //直接返回第k个
        heapsort(nums);
        return nums[nums.size() - k];
    }
private:
    void swap(vector<int>& nums, size_t i, size_t j)
    {
        if (i == j) {
            return;
        }
        assert(i < nums.size() && j < nums.size());
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void adjustdown(vector<int>& nums, size_t size, int root)
    {
        //size 表示下标
        assert(size < nums.size());
        //左右孩子的序号
        size_t Lchild = root * 2 + 1;
        size_t Rchild = root * 2 + 2;
        //只要没有左孩子 就一定没有右孩子 就一定越界了
        if (Lchild > size) {
            return;
        }
        //走到这里就说明有左孩子
        size_t maxchild = Lchild;
        if (Rchild <= size && nums[Rchild] > nums[Lchild]) {
            maxchild = Rchild;
        }
        //拿大的交换
        if (nums[maxchild] > nums[root]) {
            swap(nums, root, maxchild);
            //拿换下去的继续向下调整
            adjustdown(nums, size, maxchild); 
        }
        //如果不用向下调整 就结束 所有这个有两个出口
        //一个是调整完成
        //一个是调整到最下面
    }
    void createheap(vector<int>& nums)
    {
        //从最后一个非叶子结点开始
        int root = (nums.size() - 1 - 1) / 2;
        while(root >= 0) {
            //size 是下标
            adjustdown(nums, nums.size() - 1, root);
            root--;
        }
    }
    void heapsort(vector<int>& nums)
    {
        int root = nums.size() - 1;
        createheap(nums);
        while(root > 0) {
            swap(nums, 0, root);
            root--;
            adjustdown(nums, root, 0);
        }
    }
};
int main()
{
    vector<int> v{3, 2, 1, 5, 6, 4};
    Solution s;
    cout << s.findKthLargest(v, 2) << endl;
    return 0;
}
