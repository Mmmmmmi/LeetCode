/*
 * 给定一个整数数组，判断是否存在重复元素。
 *
 * 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
 *
 * 示例 1:
 * 输入: [1,2,3,1]
 * 输出: true
 * 示例 2:
 *
 * 输入: [1,2,3,4]
 * 输出: false
 * 示例 3:
 *
 * 输入: [1,1,1,3,3,4,3,2,4,2]
 * 输出: true
 * 
 * class Solution {
 * public:
 *     bool containsDuplicate(vector<int>& nums) {
 *     }
 * };
 */



/*
 ** 给定一个整数数组，判断是否存在重复元素。
 **
 ** 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
 **
 ** 示例 1:
 ** 输入: [1,2,3,1]
 ** 输出: true
 ** 示例 2:
 **
 ** 输入: [1,2,3,4]
 ** 输出: false
 ** 示例 3:
 **
 ** 输入: [1,1,1,3,3,4,3,2,4,2]
 ** 输出: true
 **
 ** class Solution {
 ** public:
 **     bool containsDuplicate(vector<int>& nums) {
 **     }
 ** };
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return false;

        }
        quicksort(nums, 0, nums.size() - 1);
        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;

            }

        }
        return false;

    }
private:
    void swap(vector<int>& nums, int left, int right)
    {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;

    }
    void quicksort(vector<int>& nums, int left, int right)
    {
        int start = left;
        int end = right;
        if (start >= end) {
            return;

        }
        int i = adjust(nums, start, end);
        quicksort(nums, start, i - 1);
        quicksort(nums, i + 1, end);

    }

    int adjust(vector<int>& nums, int left, int right)
    {
        //left表示开始的下标  right表示结束的下标
        int start = left;
        int end = right;
        while (start < end) {
            while (start < end && nums[start] <= nums[right]) {
                start++;

            }
            //走到这里  就说明 在mid的左边遇见了比mid大的
            while (end > start && nums[end] >= nums[right]) {
                end--;

            }
            //走到这里  就说明 在mid的右边遇见了比mid小的
            swap(nums, start, end);

        }

        swap(nums, start, right);
        return start;

    }


};
int main()
{
    vector<int> v{1, 2, 3, 1};
    Solution s;
    cout << s.containsDuplicate(v) << endl;
    return 0;

}
