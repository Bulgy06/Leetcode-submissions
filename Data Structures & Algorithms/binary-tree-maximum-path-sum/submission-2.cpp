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
    int findPath(TreeNode* root,int &res){
        if(root==NULL) return 0;
        int Lsum=max(findPath(root->left,res),0);
        int Rsum=max(findPath(root->right,res),0);
        res=max(res,root->val+Lsum+Rsum);
        return root->val +max(Lsum,Rsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int res=root->val;
        findPath(root,res);
        return res;
    }
};