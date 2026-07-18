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
private:
    bool validate(TreeNode* node,long long mini, long long maxi ){
        if(!node){
            return true;
        }
        if(!(mini<node->val && node->val<maxi)) return false;
        return validate(node->left,mini,node->val) && validate(node->right,node->val,maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root,INT_MIN,INT_MAX);
    }
};
