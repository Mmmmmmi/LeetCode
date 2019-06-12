/*
给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例 :

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

class Solution {
public:
	vector<string> letterCombinations(string digits) {

	}
};

*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	vector<string> letterCombinations(string digits) {
		string key_value[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> ret;
		string s;
		if (digits == "")
		{
			return ret;
		}
		getRet(digits, ret, "", key_value, 0);
		// 电话号  返回值 当前字符串  存储表  当前应匹配字符
		return ret;
	}

	void getRet(const string& digits, vector<string>& ret, string str, string key_value[], int key)
	{
		if (key >= digits.size())
		{
			ret.push_back(str);
			return;
		}
		for (int i = 0; i < key_value[digits[key] - '0'].size(); i++)
		{
			getRet(digits, ret, str + key_value[digits[key] - '0'][i], key_value, key + 1);
		}
	}
};
int main()
{
	Solution s;
	vector<string> ret = s.letterCombinations("234");
	for (auto e : ret)
	{
		cout << e << endl;
	}
	return 0;
}
