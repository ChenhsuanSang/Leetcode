/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 */

// @lc code=start
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        int len = text.length();
        string tf = "", ts = "", now = "";
        for(int i=0; i<len; ++i) {
            int s = i;
            while(text[i]!=' ') {
                i++;
                if(i == len) break;
            }
            tf = ts;
            ts = now;
            now = text.substr(s, i-s);
            if((tf == first) && (ts == second))
                ans.push_back(now);
        }
        return ans;
    }
};
// @lc code=end

