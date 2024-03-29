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
   #include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;

class Solution {
public:
  
void inorderTrav(TreeNode*node, vector<int>&res){
    if(!node)
        return;
    if (!node->left && !node->right)
     {
        res.push_back(node->val); 
        return; 
     }    
    if (node->left)
        inorderTrav(node->left, res); 
    res.push_back(node->val); 
    if (node->right)
        inorderTrav(node->right, res); 
    
}

vector<int> inorderTraversal(TreeNode *root)
{
    DPSolver;
    vector<int> res; 
    inorderTrav(root, res); 
    return res; 
}
};