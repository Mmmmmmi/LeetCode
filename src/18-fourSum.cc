/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {

	}
};


*/


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	void TwoSum(vector<int>& nums, int target, int left, int right, int three, int four, vector<vector<int>>& ret)
	{
		if (left >= right)
		{
			return;
		}
		while (left < right)
		{
			int gap = target - nums[left];
			int i = left + 1;
			while (i <= right)
			{
				if (nums[i] == gap)
				{
					int flag = 0;
					vector<int> temp;
					temp.push_back(four);
					temp.push_back(three);
					temp.push_back(nums[left]);
					temp.push_back(nums[i]);
					for (auto e : ret)
					{
						if (e[0] == temp[0] && e[1] == temp[1] && e[2] == temp[2] && e[3] == temp[3])
						{
							flag = 1;
							break;
						}
					}
					if (flag == 0)
					{
						ret.push_back(temp);
					}
				}
				i++;
			}
			left++;
		}
	}

	void ThreeSum(vector<int>& nums, int target, int left, int right, int four, vector<vector<int>>& ret)
	{
		if (left >= right)
		{
			return;
		}
		while (left < right)
		{
			int gap = target - nums[left];
			TwoSum(nums, gap, left + 1, right, nums[left], four, ret);
			left++;
		}
	}

	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ret;
		if (nums.size() < 4)
		{
			return ret;
		}
		sort(nums.begin(), nums.end());
		for (auto e : nums)
		{
			cout << e << " ";
		}
		cout << endl;
		int left;
		for (left = 0; left < nums.size() - 3; left++)
		{
			int gap = target - nums[left];
			ThreeSum(nums, gap, left + 1, nums.size() - 1, nums[left], ret);
		}
		return ret;
	}
};


int main()
{
	Solution s;
	vector<int> nums = {1, 0, -1, 0, -2, 2};
	//vector<int> nums = {0};
	vector<vector<int>> ret = s.fourSum(nums, 0);
	for (auto e : ret)
	{
		for (auto ee : e)
		{
			cout << ee << " ";
		}
		cout << endl;
	}
	return 0;
}