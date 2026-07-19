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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "n";
        string res="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            string level="";
            for(int i=size;i>0;i--){
                TreeNode* node=q.front();
                q.pop();
                if(node){
                    level=level+to_string(node->val)+" ";
                    q.push(node->left);
                    q.push(node->right);
                }
                else{
                    level=level+"n"+" ";
                }
            }
            res+=level;
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="n") return NULL;
        stringstream ss(data);
        string token;
        vector<string> result;
        char delimiter=' ';
        while(getline(ss,token,delimiter)) result.push_back(token);

        TreeNode* head=new TreeNode(stoi(result[0]));
        head->left=NULL;
        head->right=NULL;
        
        int i=1;
        queue<TreeNode*> r;
        r.push(head);
        while(!r.empty() && i<result.size()){
            TreeNode* parent=r.front();
            r.pop();

            if(result[i]!="n"){
                parent->left=new TreeNode(stoi(result[i]));
                r.push(parent->left);
            }
            i++;

            if(i<result.size() && result[i]!="n"){
                parent->right=new TreeNode(stoi(result[i]));
                r.push(parent->right);
            }
            i++;
        }

        return head;
    }
};
