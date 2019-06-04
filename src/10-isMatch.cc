/*************************************************************************

	> File Name: isMatch.cc
	> Created Time: 2019/6/2 14:39:48

 ************************************************************************/

 /*

 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 '.' 匹配任意单个字符
 '*' 匹配零个或多个前面的那一个元素
 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

 说明:
 s 可能为空，且只包含从 a-z 的小写字母。
 p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

 示例 1:
 输入:
	 s = "aa"
	 p = "a"
 输出:
	 false
 解释: "a" 无法匹配 "aa" 整个字符串。

 示例 2:
 输入:
	 s = "aa"
	 p = "a*"
 输出:
	 true
 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

 示例 3:
 输入:
	 s = "ab"
	 p = ".*"
 输出:
	 true
 解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。

 示例 4:
 输入:
	 s = "aab"
	 p = "c*a*b"
 输出:
	 true
 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

 示例 5:
 输入:
	 s = "mississippi"
	 p = "mis*is*p*."
 输出:
	 false

 class Solution {
 public:
	 bool isMatch(string s, string p) {
	 }
 };

 */

#include <iostream>
using namespace std;

class Solution {
public:
#if 0
	bool isMatch(string s, string p)
	{
		if (p.empty())
		{
			//p 为空  s必须为空 否则 false
			//s 为空  p不用必须为空  a*b*c* 类似的形式即可，因为 * 前面的字符可以出现0次
			return s.empty();
		}
		if (p.size() == 1)
		{
			//p.size == 1   s[0] == p[0] || p[0] == '.'
			//s == 'a' p == 'a'  || s == 'a' p == '.'
			return s.size() == 1 && (s[0] == p[0] || p[0] == '.');
		}
		if (p[1] != '*')
		{
			if (s.empty())
			{
				//s == empty && p[1] != '*' p[0] 不能出现0 次 所以返回false 
				return false;
			}
			//返回 s[0] 与 p[0] 匹配的结果 &&  后面字符匹配结果
			return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
		//p[1] == '*'
		while (!s.empty() && (s[0] == p[0] || p[0] == '.'))
		{
			//这里 p[1] == '*'  采用暴力的方式 让 * 前面的字符 也就是 p[0] 匹配 0~(n - 1) 次 s 中的相同字符 ，一次一次判断
			//因为有可能有 全部匹配成功的情况 s == 'aa' p == '.*'
			//如果不加 !s.empty 可能会访问越界，所以这里会少一次情况的匹配
			//即 p[0] 将整个 s串匹配完了
			if (isMatch(s, p.substr(2)))
			{
				return true;
			}
			s = s.substr(1);
		}
		//s == empty || * 匹配完成
		return isMatch(s, p.substr(2));
	}
#else
	bool isMatch(string s, string p)
	{
		if (p.empty()) return s.empty();
		if (p.size() > 1 && p[1] == '*')
		{
			return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
		}
		else
		{
			return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
	}
#endif
};


int main()
{
	string s = "1";
	string p = ".*";
	Solution so;
	cout << so.isMatch(s, p) << endl;
	return 0;
}
