/*
 * @lc app=leetcode.cn id=390 lang=cpp
 *
 * [390] 消除游戏
 */

// @lc code=start
class Solution {
public:
    int lastRemaining(int n) {
        int k = 1, len = n, f = 0;
        int ans = 1;
        while(len > 1) {
            if(!(f % 2))    ans += k;
            else if(len %2) ans += k;

            f = !f;
            k<<=1;
            len>>=1;
        }
        return ans;
    }
};
// @lc code=end

