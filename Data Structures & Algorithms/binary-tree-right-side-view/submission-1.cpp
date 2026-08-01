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
    vector<int> rsv;
    void dfs(TreeNode* root,int depth){
        if(!root) return;
        if(depth==rsv.size()){
            rsv.push_back(root->val);
        }
        dfs(root->right,depth+1);
        dfs(root->left,depth+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        dfs(root,0);
        return rsv;

    }
};
