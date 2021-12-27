/*
 * @lc app=leetcode.cn id=825 lang=cpp
 *
 * [825] 适龄的朋友
 */

// @lc code=start
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        int len = ages.size();
        sort(ages.begin(), ages.end());
        for(int i=0; i<len; ++i) {
            int l = ages[i] * 0.5 + 7;
            if (l > ages[i]) l = ages[i];
            int r = ages[i];
            int lpos = upper_bound(ages.begin(),ages.end(),l)-ages.begin();
            int rpos = upper_bound(ages.begin(),ages.end(),r)-ages.begin();
            ans += (rpos - lpos);
            if (ages[i] > l && ages[i] <= r)    ans--;
        }
        return ans;
    }
};
// @lc code=end

