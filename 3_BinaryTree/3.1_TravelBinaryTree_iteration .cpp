# include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  // leetcode 141
  class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* tmp = s.top();
            s.pop();
            res.emplace_back(tmp->val);
            if (tmp->right) s.push(tmp->right);
            if (tmp->left) s.push(tmp->left);
        }
        return res;
    }
};

// leetcode 94
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (cur || !s.empty())
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            TreeNode* tmp = s.top();
            s.pop();
            res.emplace_back(tmp->val);
            if (tmp->right) cur = tmp->right;
        }
        return res;
    }
};

// leetcode 145
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* tmp = s.top();
            s.pop();
            res.emplace_back(tmp->val);
            if (tmp->left) s.push(tmp->left);
            if (tmp->right) s.push(tmp->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};