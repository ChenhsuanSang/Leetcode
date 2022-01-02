/*
 * @lc app=leetcode.cn id=846 lang=cpp
 *
 * [846] 一手顺子
 */

// @lc code=start
int v[10005];

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        memset(v, 0, sizeof(v));
        int n = hand.size();
        if (n % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        for(int i=0; i<n; ++i) {
            if(v[i]) continue;
            int pos = i, val = hand[i], cnt = 1;
            v[i] = 1;
            for(int j=i+1; j<n; ++j) {
                if(!v[j] && cnt<groupSize) {
                    if(hand[j] == val+1) {
                        val++; cnt++; v[j] = 1; 
                        if(cnt == groupSize) break;
                    }
                    else if (hand[j] > val+1) return false;
                }
            }
            if(cnt < groupSize) return false;
        }
        return true;
    }
};
// @lc code=end

