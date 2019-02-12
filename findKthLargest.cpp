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
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //用堆排序的方法
        //直接返回第k个
        //
    }
private:
    void createheap(vector<int>& nums)
    {
        //从最后一个非叶子结点开始
        int root = (nums.size() - 1 - 1) / 2;
        while(root >= 0)
            adjustdown(nums, root);
            root--;
        }
    }
    void adjustdown(vector<int>& nums, int i)
    {
        
    }
    
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

