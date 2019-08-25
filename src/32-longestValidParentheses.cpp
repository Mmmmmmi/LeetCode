/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

class Solution {
public:
	int longestValidParentheses(string s) {

	}
};

*/



#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:


#if 0
	// 暴力法 时间复杂度过大
	int longestValidParentheses(string s) {
		int max = 0;
		for (int i = 0; i < s.size(); i++)
		{
			stack<char> tmpstack;
			int cur = 0;
			for (int j = i; j < s.size(); j++)
			{

				if (s[j] == '(')
				{
					//左括号压栈
					tmpstack.push('(');
				}
				else if (s[j] == ')')
				{
					if (tmpstack.empty())
					{
						cur = 0;
					}
					else
					{
						cur += 2;
						tmpstack.pop();
						if (cur > max && tmpstack.empty())
						{
							max = cur;
						}
					}
				}
			}

		}
		return max;
	}
#endif

	int longestValidParentheses(string s)
	{
		//动态规划方法
		int result = 0;
		vector<int> dp(s.size(), 0);
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] == ')')
			{
				if (s[i - 1] == '(')
				{
					dp[i] = ((i > 1) ? dp[i - 2] : 0) + 2;
					//)
				}
				else if ((i - dp[i - 1] > 0) && (s[i - dp[i - 1] - 1] == '('))
				{
					//()(()) 
					dp[i] = dp[i - 1] + ((i - dp[i - 1]) > 1 ? dp[i - dp[i - 1] - 2] : 0) + 2;
					//用dp[i - 1] 加上 前面可能续上的 dp[i - dp[i - 1] - 1] 的 再加 2
				}
				if (dp[i] > result)
				{
					result = dp[i];
				}
			}
		}
		return result;
	}
};

int main()
{
	string input;
	Solution s;
	input = "()(())";
	cout << s.longestValidParentheses(input) << endl;
	return 0;
}