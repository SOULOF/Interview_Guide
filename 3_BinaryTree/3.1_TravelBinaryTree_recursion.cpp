# include <bits/stdc++.h>
//leetcode 144 

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        help(root, res);
        return res;
    }
    void help(TreeNode* root, vector<int> &res)
    {
        if (!root) return;
        res.emplace_back(root->val);
        help(root->left, res);
        help(root->right, res);
    }
};

// leetcode 94
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        help(root, res);
        return res;
    }
    void help(TreeNode* root, vector<int> &res)
    {
        if (!root) return;
        help(root->left, res);
        res.emplace_back(root->val);
        help(root->right, res);
    }
};

// leetcode 145
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        help(root, res);
        return res;
    }
    void help(TreeNode* root, vector<int> &res)
    {
        if (!root) return;
        help(root->left, res);
        help(root->right, res);
        res.emplace_back(root->val);
    }
};