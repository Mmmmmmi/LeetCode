
/*给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

c:
int maxSubArray(int* nums, int numsSize) {
    
}

c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    }
};

*/



#if 0
#include <stdio.h>

int MaxSubArray(int* nums, int numsSize) {
    int summax = nums[0];
    int nowmax = nums[0];
    int i = 1;
    while (i < numsSize) {
        if (nums[i] >= 0) {
            if (nowmax >= 0) {
                nowmax += nums[i];
            }
            else {
                nowmax = nums[i];
            }
        }
        else if (nums[i] < 0){
                if (nowmax >= 0) {
                    nowmax += nums[i];
                }
                else {
                    nowmax = nums[i];
                }
            }
        if (nowmax > summax) {
            summax = nowmax;
        }
        i++;
    }
    return summax;
}

#else

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = nums[0];
        for (auto e: nums) {
            if (sum >= 0) {
                sum += e;
            }else {
                sum = e;
            }
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};

#endif


int main()
{
    /*
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
   // int nums[] = {1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("numsSize = %d\n", numsSize);
    printf("%d\n", MaxSubArray(nums, numsSize));
    */
    vector<int> v = {-1, 2, 3};
    Solution s;
    cout << s.maxSubArray(v) << endl;
    return 0;
}
