/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";
        if(!root) return str;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*root=q.front();
            q.pop();
            if(!root){
                str.append("#,");
            }else{
                str.append(to_string(root->val)+',');
            }
            if(root){
                q.push(root->left);
                q.push(root->right);
            }
        }
        return str;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size()==0)return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
         TreeNode*root=new TreeNode(stoi(str));
         queue<TreeNode*>q;
         q.push(root);
         while(!q.empty()){
             TreeNode*root=q.front();
             q.pop();
             string str;
             getline(s,str,',');
             if(str=="#")
             root->left=nullptr;
             else{
                root->left=new TreeNode(stoi(str));
                q.push(root->left);
             }
             getline(s,str,',');
             if(str=="#") root->right=nullptr;
             else{
                root->right=new TreeNode(stoi(str));
                q.push(root->right);
             }
         }
        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));