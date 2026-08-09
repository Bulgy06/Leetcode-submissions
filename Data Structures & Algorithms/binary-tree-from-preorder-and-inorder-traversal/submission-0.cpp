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
    unordered_map<int,int> indices;
    int pre_index=0;
    void buildHashMap(vector<int> &inorder){
        for(int i=0;i<inorder.size();i++){
            indices[inorder[i]]=i;
        }
        return;
    }

    TreeNode* dfs(vector<int> &preorder,int l , int r){
        if(l>r) return NULL;
        int root_val=preorder[pre_index++];
        TreeNode* root=new TreeNode(root_val);
        int mid=indices[root_val];
        root->left=dfs(preorder,l,mid-1);
        root->right=dfs(preorder,mid+1,r);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        buildHashMap(inorder);
        if(preorder.empty() || inorder.empty()) return NULL;
        return dfs(preorder,0,inorder.size()-1);
        

    }
};
