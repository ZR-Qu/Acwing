/* 236. 二叉树的最近公共祖先 LCA */
# include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode* , int> depth; 
        unordered_map<TreeNode*, TreeNode*> fa;
        // depth.reserve(20010);
        // fa.reserve(20010);

        depth[root] = 1;
        fa[root] = nullptr;

        queue<TreeNode*> qu;
        qu.push(root);
        while(qu.size()){
            auto t = qu.front();
            qu.pop();

            auto lc = t -> left;
            auto rc = t -> right;
            
            if(lc != NULL){
                depth[lc] = depth[t] + 1;
                fa[lc] = t;
                qu.push(lc);
            }
            if(rc != NULL){
                depth[rc] = depth[t] + 1;
                fa[rc] = t;
                qu.push(rc);
            }
        }

        if(depth[p] < depth[q]) swap(p,q);
        while(depth[p] > depth[q]) p = fa[p];
        while(p!=q){
            p = fa[p];
            q = fa[q];
        }
        return p;
    }
};