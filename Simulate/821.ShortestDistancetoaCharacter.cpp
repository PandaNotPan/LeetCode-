/**
 * 给你一个字符串 s 和一个字符 c ，且 c 是 s 中出现过的字符。
 * 返回一个整数数组 answer ，其中 answer.length == s.length 且 answer[i] 是 s 中从下标 i 到离它 最近 的字符 c 的 距离 。
 * 两个下标 i 和 j 之间的 距离 为 abs(i - j) ，其中 abs 是绝对值函数。
 * 
 * -----------------------------------------------
 * 输入：s = "loveleetcode", c = "e"
 * 输出：[3,2,1,0,1,0,0,1,2,2,1,0]
 * -----------------------------------------------
 *
 * 
*/

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int length = s.size();
        vector<int> min_disatance(s.size(), -1);

        for(int i = 0, masked = -length; i < s.size(); ++i){
            if(s[i] == c){
                masked = i;
            }
            min_disatance[i] = i - masked;
        }

        for(int i = length - 1, masked = 2 * length; i >= 0; --i){
            if(s[i] == c){
                masked = i;
            }
            min_disatance[i] = min(min_disatance[i], masked-i);
        }

        return min_disatance;
    }
};