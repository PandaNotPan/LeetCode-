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
    int addDigest(int number){
        int counter = 0;
        while(number > 0){
            counter += number % 10;
            number = number / 10;
        }
        return counter;
    }

    void dfs(int row, int col, int k, vector<vector<int>>& visited, int& res){
        if(row < 0 || row >= visited.size() || col < 0 || col >=visited[0].size()
          || addDigest(row) + addDigest(col) > k || visited[row][col]){
              return ;
        }
        visited[row][col] = 1;
        res++;
        dfs(row-1, col, k, visited, res);
        dfs(row+1, col, k, visited, res);
        dfs(row, col+1, k, visited, res);
        dfs(row, col-1, k, visited, res);
    }

    int movingCount(int m, int n, int k) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int res = 0;
        dfs(0, 0, k, visited, res);

        return res;
    }
};

int main()
{
    Solution s = Solution();
    cout << s.movingCount(5,4,5);
    return 0;
}

