/*

����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�

ʾ�� :

���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է���[0, 1]


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
	}
};

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> umap;
		vector<int> ret;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			int temp = target - nums[i];
			if (umap.find(temp) != umap.end())
			{
				ret.push_back(umap[temp]);
				ret.push_back(i);
				break;
			}
			umap[nums[i]] = i;
		}
		return ret;
	}
};
int main()
{
	return 0;
}


