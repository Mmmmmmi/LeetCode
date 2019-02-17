/* 
 *  * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: true
 * 解释: 20 = 1
 * 示例 2:
 * 
 * 输入: 16
 * 输出: true
 * 解释: 24 = 16
 * 示例 3:
 * 
 * 输入: 218
 * 输出: false
 *
 *class Solution {
 *public:
 *   bool isPowerOfTwo(int n) {
 *   }
 *};
 */
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
#if 0
        int i = 2;
        int j = 0;
        if (n < 1) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        while((i << j) <= n) {
            if ((i << j) == n) {
                return true;
            }
            j++;
        }
        return false;
#else
        if (n < 1) {
            return false;
        }

        if ((n & (n - 1)) == 0) {
            return true;
        }
        return false;

#endif
    }
};

int main()
{
    Solution s;
    cout << s.isPowerOfTwo(9) << endl;
    return 0;
}

