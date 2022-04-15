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