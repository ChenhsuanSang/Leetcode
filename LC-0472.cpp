/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */

// @lc code=start
int const MAXN = 1e5 + 5;
bool cmp(const string A, const string B) { return A.length() < B.length(); }

class Trie {
public:
    int trie[MAXN][26];
    int _end[MAXN];
    int tot = 1;
    Trie() {
        memset(trie, 0, sizeof(trie));
        memset(_end, 0, sizeof(_end));
    }
    
    void insert(string word) {
        int p = 1;
        for(auto chr : word) {
            int ch = chr - 'a';
            if(trie[p][ch] == 0) trie[p][ch] = ++tot;
            p = trie[p][ch];
        }
        _end[p] = true;
    }
    
    bool search(string word) {
        int p = 1;
        for(auto chr : word) {
            p = trie[p][chr -'a'];
            if(p == 0) return false;
        }
        return _end[p];
    }
    
    bool startsWith(string prefix) {
        int p = 1;
        for(auto chr : prefix) {
            p = trie[p][chr-'a'];
            if(p == 0) return false; 
        }
        return true;
    }

    bool checkLink(string word, int s= 0) {
        int len = word.length(), p = 1;
        if(s == len) return true;
        for(int i=s; i<len; ++i) {
            p = trie[p][word[i] - 'a'];
            if(p == 0) return false; 
            if(_end[p]) if(checkLink(word, i+1)) return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        Trie* dic = new Trie();
        
        sort(words.begin(), words.end(), cmp);

        for(auto iter : words)  {
            if(iter.length() == 0) continue;
            if(dic->checkLink(iter)) ans.push_back(iter);
            else dic->insert(iter);
        }
        return ans;
    }
};
// @lc code=end

