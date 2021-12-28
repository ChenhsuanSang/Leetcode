/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
int const MAXN = 1e6 + 5;
class Trie {
public:
    int trie[MAXN][26];
    int end[MAXN];
    int tot = 1;
    Trie() {
        memset(trie, 0, sizeof(trie));
        memset(end, 0, sizeof(end));
    }
    
    void insert(string word) {
        int len = word.length(), p = 1;
        for(int i=0; i<len; ++i) {
            int ch = word[i] - 'a';
            if(trie[p][ch] == 0) trie[p][ch] = ++tot;
            p = trie[p][ch];
        }
        end[p] = true;
    }
    
    bool search(string word) {
        int len = word.length(), p = 1;
        for(int i=0; i<len; ++i) {
            p = trie[p][word[i]-'a'];
            if(p == 0) return false;
        }
        return end[p];
    }
    
    bool startsWith(string prefix) {
        int len = prefix.length(), p = 1;
        for(int i=0; i<len; ++i) {
            p = trie[p][prefix[i]-'a'];
            if(p == 0) return false; 
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

