/**
 * 给你一个 m x n 的整数网格 accounts ，
 * 其中 accounts[i][j] 是第 i​​​​​​​​​​​​ 位客户在第 j 家银行托管的资产数量。
 * 返回最富有客户所拥有的 资产总量 。
 * 
 * 
 * ---------------------------------------
 * 输入：accounts = [[1,2,3],[3,2,1]]
 * 输出：6
 * 解释：
 * 第 1 位客户的资产总量 = 1 + 2 + 3 = 6
 * 第 2 位客户的资产总量 = 3 + 2 + 1 = 6
 * 两位客户都是最富有的，资产总量都是 6 ，所以返回 6 
 * ---------------------------------------
 * 
 *
 * m = accounts.length
 * n = accounts[i].length
 * 1 <= m, n <= 50
 * 1 <= accounts[i][j] <= 100
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int  maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(auto& user: accounts){
            int temp = accumulate(user.begin(),user.end(),0);
            ans = ans<temp?temp:ans;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> sample = {{1,5},{7,3},{3,5}};
    Solution s = Solution();
    cout << s.maximumWealth(sample);

    return 0;
}