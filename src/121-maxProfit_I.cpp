/*
 *  给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 *
 *  如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
 *
 *  注意你不能在买入股票前卖出股票。
 *
 *  示例 1:
 *
 *  输入: [7,1,5,3,6,4]
 *  输出: 5
 *  解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 *       注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
 *  示例 2:
 *
 *  输入: [7,6,4,3,1]
 *  输出: 0
 *  解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 *  
 *  class Solution {
 *  public:
 *      int maxProfit(vector<int>& prices) {
 *      }
 *  };
 *
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //动态规划问题，假设前一天都是收益最大的。就判断能不能在今天卖
        size_t buy = 0;
        size_t sell = 0;
        int maxprofix = 0;      //最大收益
        int profix = 0;         //收益
        for (sell = 0; sell < prices.size(); sell++) {
            //假设上一次都是收益最大的，因此 判断今天收益会不会更大，如果更大的话就更新收益的数据 否则就不变
            profix = prices[sell] - prices[buy];
            if (maxprofix < profix) {
                maxprofix = profix;
            }

            //如果今天的价格是最低的，那就假设在今天买入
            if (prices[sell] < prices[buy]) {
                buy = sell;
            }
        }
        return maxprofix;
    }

};
int main()
{
    vector<int> prices{7, 6, 4, 3, 1};
    Solution s;
    cout << "maxprofit = " << s.maxProfit(prices) << endl;
    return 0;
}
