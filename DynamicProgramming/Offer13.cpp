/**
 * 剑指 Offer 13. 机器人的运动范围
 * 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
 * 一个机器人从坐标 [0, 0]的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行，坐标和列坐标的数位之和大于k的格子。
 * 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
 * 但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
 * 
 * 
 * -------------------------------------------
 * 输入：m = 2, n = 3, k = 1
 * 输出：3
 * -------------------------------------------
 * 
 * 
 * -------------------------------------------
 * 输入：m = 3, n = 1, k = 0
 * 输出：1
 * -------------------------------------------
 * 
 * 
 * 1 <= n,m <= 100
 * 0 <= k <= 20
 * 
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {    
public:
    int calc(int x){int res=0;for(;x;x/=10)res+=x%10;return res;}
    int movingCount(int m,int n,int k){
        if(!k)return 1;
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=1;
        vis[0][0]=1;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if((i==0&&j==0)||calc(i)+calc(j)>k)continue;
                if(i-1>=0)vis[i][j]|=vis[i-1][j];
                if(j-1>=0)vis[i][j]|=vis[i][j-1];
                ans+=vis[i][j];
            }
        return ans;
    }
};


int main()
{
    Solution s = Solution();
    cout << s.movingCount(5,4,5);
    return 0;
}

