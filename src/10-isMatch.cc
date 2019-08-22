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
#include <vector>
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
#endif


#if 0
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

#if 0
    // 递归的自底向上方法
    // 
    // 
	void Print(vector<vector<bool>>& output)
	{
		for (auto e : output)
		{
			for (auto ee : e)
			{
				cout << ee << " ";
			}
			cout << endl;
		}
	}



	bool isMatch(string s, string p) {
		int slen = s.size();
		int plen = p.size();
		vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));
		/*
		   c * a * b
		a
		a
		b

		*/
		//递归 可以从前往后 也可以从后往前，这里先用从后往前
		//从后往前的话，那么dp[i][j] 表示的就是 s[i, s.size()) p[j, p.size()) 的匹配情况
		//那么  就得从后往前求

		//从后往前的情况下，当
		dp[slen][plen] = true;   //两个都到结尾了，所以两个都是空 因此是匹配的;

		/*
		   c * a * b
		a
		a
		b
		*/

		for (int i = slen; i >= 0; --i)  //这里相等是因为
										//s = aa      p = a*  情况
		{
			cout << "i == " << i <<  endl;
			for (int j = plen - 1; j >= 0; --j)   //因为这里j 会判断后面的字符 然后 dp的大小其实是比正常的多一个行和列大小的  所以 这里 -1 就好
			{
				//这波 比较的 应该是 s[i] 和 p[j]
				//当时如果  p[j + 1] == '*'  ，那么情况就有可能不用 所以应该也判断它的情况
				//这里求的是 当前位置的 s[i] 和 p[j] 的情况  只是单纯的两个字符想不想等
				bool curMatch = (i < slen && (s[i] == p[j] || p[j] == '.'));  

				if (j + 1 < plen && (p[j + 1] == '*'))
				{
					//就是看 p 串的 j 字符(p[j]) 后面 是不是 *
					//如果是的话  那么  说明 p[j] 可能出现 0 次 或者 多次
					dp[i][j] = dp[i][j + 2]  //出现0次
						|| curMatch && dp[i + 1][j];  //出现一次或者多次的情况 就看 出现这种情况后，剩下的字符串能不能匹配
				}
				else
				{
					//如果它后面不是 *  那就判断两个想不想等就好了
					dp[i][j] = curMatch && dp[i + 1][j + 1];   //不光要管本字符的情况，还要管后面的是否匹配成功了
				}

			}
			Print(dp);
		}
		return dp[0][0];
	}
#endif 


    //动归的自顶向下算法
    //
    //
    //
    //
    //
    // 这里面的 dp[i][j]   存储的就是 s[i, i.size()) p[j, j.size()) 是否匹配

	void Print(vector<vector<int>>& output)
	{
		for (auto e : output)
		{
			for (auto ee : e)
			{
				cout << ee << " ";
			}
			cout << endl;
		}
	}

    bool _isMatch(string s, string p, int i, int j, vector<vector<int>>& dp)
    {
        //判断情况
        if (dp[i][j] != -1)
        {
            //已经求过是否匹配了，直接返回就好
            return dp[i][j] == 1;
        }
        bool result = false;
        if (j == p.size())
        {
            //如果 p为空  那么 s 也得为空
            result = i == s.size();
        }
        else
        {
            //求出当前字符的匹配状态
            bool curMatch = i < s.size() && (s[i] == p[j] || p[j] == '.');
            //判断p[j + 1] 有没有可能为 '*'
            if ((j + 1 < p.size()) && (p[j + 1] == '*'))
            {
                cout << "result = _isMatch(s, p, i, j + 2, dp) || (curMatch && _isMatch(s, p, i + 2, j, dp))); "<< "  i  == "  << i   << "   j + 2 ==  " << j + 2 << "  i + 1 == " << i + 1 << "  j == " << j  << endl;
                //这里也是两种情况  * 前面的字符出现 0次  和 出现多次
                result = (
                          //0次  那么就是 把 * 和它前面的那个字符都跳过了
                          _isMatch(s, p, i, j + 2, dp)   
                          //这里等于直接跳过当前的字符 然后出现两次或者更多的情况 交给后面去处理
                          || (curMatch && _isMatch(s, p, i + 1, j, dp)));  
                Print(dp);
            }
            else
            {
                //那么 当它后面不是 ‘*’ 的时候，就只需要判断 自己当前字符是否匹配 和 后面 的是不是匹配了
                cout << "result = curMatch && _isMatch(s, p, i + 1, j + 1, dp);" << "   i + 1 == "  << i + 1  << "   j + 1 ==  " << j + 1 << endl;
                result = curMatch && _isMatch(s, p, i + 1, j + 1, dp);
                Print(dp);
            }
        }
        dp[i][j] = result ? 1 : 0; 
        return result;
    }


    bool isMatch(string s, string p) 
    {
        //这里要用到递归的话 就再调用一个函数叭   
        //先创建动归的dp 
        //   -1 表示 没有求值的  0 表示 不匹配   1 表示匹配
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        //创建好之后 开始调用递归函数 进行匹配
        return _isMatch(s, p, 0, 0, dp);
    }

};


int main()
{
	string s = "aab";
	string p = "c*a*b";
    cout << "s == " << s << endl;
    cout << "p == " << p << endl;
	Solution so;
	cout << so.isMatch(s, p) << endl;
	return 0;
}
