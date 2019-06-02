
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//动态规划问题
		int  sumprofit = 0;  //利益和  
		int maxprofit = 0;   //最大利益
		int  profit = 0;     //利益
		size_t  buyday = 0;     //购买日期
		size_t  sellday = buyday + 1;    //出售日期
		while (sellday < prices.size()) {
			profit = prices[sellday] - prices[buyday];
			//判断收益情况
			//有三种 大于最大  等于0  小于最大
			//如果大于最大 那么继续向后走
			//如果小于最大 那么今天的就是新的买入的时间 将之前的加上 并且清空maxprofit 并且调整日期
			//如果等于最大 那就说明 今天的可能和买入的是相等的  那么就让买入的变成今天的 
			//然后由于不能当天卖出 就让卖出的向后走一天
			//卖出的可能走出去 所以 买入的要一直小于size-1;
			if (profit == maxprofit) {
				//第一次进来 和 当天价格与买入价格相等的时候   第二种情况 只有是连续的 比如1111
				//重置后 最大的要清零
				sellday = sellday + 1;
				if (sellday == prices.size()) {
					sumprofit += maxprofit;
				}
			}
			else if (profit > maxprofit) {
				maxprofit = profit;
				sellday++;
				if (sellday == prices.size()) {
					sumprofit += maxprofit;
				}
			}
			else if (profit < maxprofit) {
				sumprofit += maxprofit;
				maxprofit = 0;
				buyday = sellday;
				sellday = buyday + 1;
			}
		}
		return sumprofit;
	}
};


int main()
{
	//vector<int> prices{7, 1, 5, 3, 6, 4};
	//vector<int> prices{6, 1, 3, 2, 4, 7};
	//vector<int> prices{ 5,2,3,2,6,6,2,9,1,0,7,4,5,0 };
	vector<int> prices{ 1, 9, 6, 9, 1, 7, 1, 1, 5, 9, 9, 9 };
	//vector<int> prices{1, 2, 3, 4, 5};
	Solution s;
	cout << s.maxProfit(prices) << endl;
	return 0;
}
