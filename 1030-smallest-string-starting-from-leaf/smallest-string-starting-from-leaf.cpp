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
class Solution {
public:
    vector<string> res;
    void f(TreeNode* root, string ans) {
        if (root == NULL)
            return;
        if (root->left == NULL & root->right == NULL) {
            ans += 'a' + root->val;
            reverse(ans.begin(), ans.end());
            res.push_back(ans);
            ans.clear();
            return;
        }
        ans += 'a' + root->val;
        f(root->left, ans);
        f(root->right, ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans;
        if (root == NULL)
            return ans;
        f(root, ans);
        sort(res.begin(), res.end());
        return res[0];
    }
};