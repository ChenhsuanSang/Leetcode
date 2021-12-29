/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int const inf = 0x3f3f3f3f;

class Solution {
public:

    struct Node {
        TreeNode* node;
        int deep = 0;
    }node[100005];

    bool isEvenOddTree(TreeNode* root) {
        int cnt = 0, deep = -1;
        int check = 0, cmp = 0;
        queue<Node> q;
        node[cnt].node = root;
        node[cnt].deep = 0;
        q.push(node[cnt++]);

        while(!q.empty()) {
            TreeNode *tmp = q.front().node;
            int now = q.front().deep;
            q.pop();
            if(now > deep)  {
                check = !check;
                cmp = tmp->val + (check ? -1:1) ;
                deep++;
            }
            if(tmp->val % 2 != check) return false;
            if(((tmp->val - cmp > 0)!=check) || cmp == tmp->val) return false;
            cmp = tmp->val;
            if(tmp->left) {
                node[cnt].node = tmp->left; node[cnt].deep = deep+1;
                q.push(node[cnt++]);
            }
            if(tmp->right) {
                node[cnt].node = tmp->right; node[cnt].deep = deep+1;
                q.push(node[cnt++]);
            }
        }
        return true;
    }
};
// @lc code=end

