/* 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
* 
* 说明:
* 
* 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
* 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
* 示例:
* 
* 输入:
* nums1 = [1,2,3,0,0,0], m = 3
* nums2 = [2,5,6],       n = 3
* 
* 输出: [1,2,2,3,5,6]
* ass Solution {
* public:
*     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {}
* };
*
*
*
*/ 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int size = m + n;
        while(i < m && j < n) {
            if (nums1[i] > nums2[j]) {
                nums1.insert(nums1.begin() + i, nums2[j]);     
                m++;
                j++;
            }
            i++;
        }
        while(j < n) {
            nums1.insert(nums1.begin() + i, nums2[j]);     
            i++;
            j++;
        }
        nums1.resize(size);
    }
};


int main()
{
    vector<int> num1{1, 2, 3 ,0, 0, 0};
    vector<int> num2{2, 5, 6};
    Solution s;
    s.merge(num1, 3, num2, 3);
    for (auto e : num1) {
        cout << e;
    }
    cout << endl;
    return 0;
}

