/*
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 *
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 *
 * 示例 1:
 *
 * 输入: [3,2,3]
 * 输出: 3
 * 示例 2:
 *
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * class Solution {
 * public:
 *     int majorityElement(vector<int>& nums) {
 *             
 *                 }
 * };
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int count = 1;
        for (size_t i = 0; i < nums.size(); i++) {
            if (major == nums[i]) {
                count++;

            }else {
                count--;

            }
            if (count == 0) {
                major = nums[i];
                count = 1;

            }

        }
        return major;
        /*
        for (size_t i = 0; i < nums.size() - 1; i++) {
            int flag = 0;
            for (size_t j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    flag = 1;
                }
            }
            if (flag == 0) {
                break;
            }
        }
        return nums[nums.size() / 2];
        */
    }
};

int main()
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 1, 1, 2, 2, 2, 2, 2, 2, 2};
    Solution s;
    cout << s.majorityElement(v1) << endl;
    return 0;
}

