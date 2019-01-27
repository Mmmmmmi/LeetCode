/* 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 * 
 * 
 * class Solution {
 * public:
 *     vector<vector<int>> subsets(vector<int>& nums) {
 * 
 *     }
 * };
 */ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end()); // 输出要求有序
        vector<vector<int> > result;
        vector<int> path;
        subsets(S, path, 0, result);
        return result;
    }
private:
    
    static void subsets(const vector<int> &S, vector<int> &path, size_t step,
                        vector<vector<int> > &result) {
        /*
        if (step == S.size()) {
            result.push_back(path);
            cout << "cout << path: " << endl;
            for (auto e : path)
            {
                cout << e;
            }
            cout << endl;
            return;
            
        }
        // 不选S[step]
        subsets(S, path, step + 1, result);
        // // 选S[step]
        path.push_back(S[step]);
        cout << "cout << path: " << endl;
        for (auto e : path)
        {
            cout << e;
        }
        cout << endl;
        subsets(S, path, step + 1, result);
        path.pop_back();
        */

        //对于
        //
        if (step == S.size()) {
            result.push_back(path);
            return;
        }

        //每个元素只有两种选择
        //选上 或者 选不上
        //然后继续向下递归 
        //等到回来的时候，将添加的再去掉 返回上一层 重新往下走
        //如果是没有当前元素的话，就直接往下走
        subsets(S, path, step + 1, result);
        //如果是有元素的话就吧当前元素加进去
        path.push_back(S[step]);
        subsets(S, path, step + 1, result);
        //返回的时候，再把添进去的元素取出来
        path.pop_back();


        //
    }
    

};

int main()
{
    vector<int> v = {1, 2};
    Solution s;
    vector<vector<int>> vret;
    vret = s.subsets(v);
    for(auto e:vret) {
        for (auto e1:e)
            cout << e1 << "  ";
        cout << endl;
    }
    return 0;
}

