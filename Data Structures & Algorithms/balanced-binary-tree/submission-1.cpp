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
    int findHeight(TreeNode* root){
        if(!root) return 0;
        return 1+max(findHeight(root->left),findHeight(root->right));
    }
    bool solve(TreeNode* root){
        if(root==NULL) return true;
        int lheight=0;
        int rheight=0;
        lheight=findHeight(root->left);
        rheight=findHeight(root->right);
        if(solve(root->left) && solve(root->right) && abs(lheight-rheight)<=1){
            return true;
        }
        else{
            return false;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        return solve(root);
    }
};
