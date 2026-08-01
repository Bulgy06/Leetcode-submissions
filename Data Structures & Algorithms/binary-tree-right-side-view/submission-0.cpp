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
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        rsv.push_back(root->val);
        while(!q.empty()){
            int lastSeen=INT_MIN;
            int size=q.size();
            for(int i=size;i>0;i--){
                TreeNode* r=q.front();
                q.pop();
                if(r->right){
                    lastSeen=r->right->val;
                }
                else{
                    if(r->left) lastSeen=r->left->val;
                }
                if(r->left) q.push(r->left);
                if(r->right) q.push(r->right);
            }
            if(lastSeen!=INT_MIN) rsv.push_back(lastSeen);
        }
        return rsv;
    }
};
