/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

示例 1 :

输入: dividend = 10, divisor = 3
	输出 : 3
	示例 2 :

	输入 : dividend = 7, divisor = -3
	输出 : -2
	说明 :

	被除数和除数均为 32 位有符号整数。
	除数不为 0。
	假设我们的环境只能存储 32 位有符号整数，其数值范围是[−231, 231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

class Solution {
public:
	int divide(int dividend, int divisor) {

	}
};

*/

#include <iostream>
using namespace std;


class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0)
		{
			return 0;
		}
		if (dividend == INT_MIN && divisor == -1)
		{
			//返回的结果应该是 -INT_MIN 用正数表示就会溢出
			return INT_MAX;
		}
		if (dividend == INT_MIN && divisor == 1)
		{
			//有可能是 INT_MIN / 1
			return INT_MIN;
		}
		//如果是最小的负数，求绝对值就会出现问题
		unsigned int t = dividend == INT_MIN ? 0x80000000 : abs(dividend);
		unsigned int d = divisor == INT_MIN ? 0x80000000 : abs(divisor);
		int ret = 0;
		for (int i = 31; i >= 0; i--)
		{
			if ((t >> i) >= d)
			{
				//t / 2^n >= d
				//t >= d * 2^n
				ret += 1 << i;
				t -= d << i;
			}
		}
		return (dividend ^ divisor) >= 0 ? (int)ret : -(int)ret;
	}
};


int main()
{
	Solution s;
	cout << s.divide(10, 3) << endl;
	return 0;
}
