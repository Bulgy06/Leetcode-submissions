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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||!p||!q) return NULL;
        TreeNode* larger;
        TreeNode* smaller;
        if(p->val>q->val){
            larger=p;
            smaller=q;
        }
        else{
            larger=q;
            smaller=p;
        }
        if(smaller->val<root->val && larger->val<root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(smaller->val>root->val && larger->val>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return root;
        }
    }
};
