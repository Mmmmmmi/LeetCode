
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		//��̬�滮����
		int  sumprofit = 0;  //�����  
		int maxprofit = 0;   //�������
		int  profit = 0;     //����
		size_t  buyday = 0;     //��������
		size_t  sellday = buyday + 1;    //��������
		while (sellday < prices.size()) {
			profit = prices[sellday] - prices[buyday];
			//�ж��������
			//������ �������  ����0  С�����
			//���������� ��ô���������
			//���С����� ��ô����ľ����µ������ʱ�� ��֮ǰ�ļ��� �������maxprofit ���ҵ�������
			//���������� �Ǿ�˵�� ����Ŀ��ܺ����������ȵ�  ��ô��������ı�ɽ���� 
			//Ȼ�����ڲ��ܵ������� ���������������һ��
			//�����Ŀ����߳�ȥ ���� �����ҪһֱС��size-1;
			if (profit == maxprofit) {
				//��һ�ν��� �� ����۸�������۸���ȵ�ʱ��   �ڶ������ ֻ���������� ����1111
				//���ú� ����Ҫ����
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
