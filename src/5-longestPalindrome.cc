/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"

class Solution {

public:
    string longestPalindrome(string s) {
    }
};
*/

#if 0
///////////////////////C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * LongestPalindrome(char *s)
{
    int i = 0;
    int tmp[1000] = {0};
    int cur = 0;
    int len = 0;
    int now = 0;
    int jmp = 0;
    int left = 0;
    int right = 0;
    int max = 0;
    char *ret = NULL;
    if (s == NULL) {
        return NULL;
    }
    len = strlen(s);
    while(cur < len) {  //总体指针
        now = cur;
        jmp = 0;
        left = 0;
        right = 0;
        while (now < len) {         //往前找与头相等的
            if(now != cur && s[now] == s[cur]) {    //从两头往中间走
                left = cur;
                right = now;
                while (left < right && s[left] == s[right]) {             
                    left++;
                    right--;
                }
                if (left >= right) {         //走到中间
                    tmp[cur] = jmp;
                    if (jmp > tmp[max]) {
                        max = cur;
                    }
                }
            }
            now++;
            jmp++;
        }
        cur++;
    }
    ret = (char *) malloc (sizeof(char) * (tmp[max] + 2));  //大小比小标多1 再多出一个空间 放 \0
    if (ret == NULL) {
        return NULL;
    }
    for (i = 0; i <= tmp[max]; i++) {
        ret[i] = s[max + i];
    }
    return ret;
}


int main()
{
    char s[] = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    char *ret = LongestPalindrome(s);
    printf("%s\n", ret);
    return 0;
}

#endif
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2)
		{
			return s;
		}
		vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
		/*
		  0 1 2 3 4
		  b a b a d
	 0  b 1
	 1  a   1
	 2  b     1
	 3  a       1
	 4  d         1
		*/
		// 00 01 02 03
		//    11 11 12
		//       22
		int curlong = 0;
		string ret = "";
		for (int right = 0; right < s.size(); ++right)
		{
			for (int left = 0; left <= right; ++left)
			{
				if (s[left] == s[right])
				{
					if (right - left < 2)
					{
						//长度为 1 和 2 的时候
						dp[left][right] = true;
						if (right - left + 1 > curlong)
						{
							curlong = right - left + 1;
							ret = s.substr(left, curlong);
						}
					}
					else
					{
						//长度大于 2
						//因为这里是最后才走到对角线 所以提前赋值为true
						if ((left + 1) == (right - 1))
						{
							dp[left + 1][right - 1] = true;
						}
						if (dp[left + 1][right - 1] == true)
						{
							dp[left][right] = true;
							if (right - left + 1 > curlong)
							{
								curlong = right - left + 1;
								ret = s.substr(left, curlong);
							}
						}
					}
				}
			}
		}
		return ret;
	}
};

int main()
{
	Solution s;
	string input;
	cin >> input;
	cout << s.longestPalindrome(input) << endl;
	return 0;
}