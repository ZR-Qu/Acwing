/*  226.翻转二叉树
    https://leetcode.cn/problems/invert-binary-tree/description/?envType=problem-list-v2&envId=2cktkvj
*/

#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        TreeNode *lc = root -> left;
        TreeNode *rc = root -> right;
        root -> left = rc;
        root -> right = lc;
        invertTree(lc);
        invertTree(rc);

        return root;
    }
};