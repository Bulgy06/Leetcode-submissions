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
    int findNodes(TreeNode* node,int seenMax,int &goodnodes){
        if(!node) return 0;
        if(node->val>=seenMax){
            seenMax=node->val;
            return goodnodes=1+findNodes(node->left,seenMax,goodnodes)+findNodes(node->right,seenMax,goodnodes);
        }
        else{
            return goodnodes=findNodes(node->left,seenMax,goodnodes)+findNodes(node->right,seenMax,goodnodes);
        }
    }

public:
    int goodNodes(TreeNode* root) {
        int goodnodes=0;
        return findNodes(root,INT_MIN,goodnodes);
    }
};
