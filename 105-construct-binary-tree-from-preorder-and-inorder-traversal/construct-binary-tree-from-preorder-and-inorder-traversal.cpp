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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode*root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode*buildTree(vector<int>&preorder,int prestart,int preend,
    vector<int>&inorder,int instart,int inend,map<int,int>&mp){
     if(prestart>preend||instart>inend) return nullptr;
     TreeNode*root=new TreeNode(preorder[prestart]);
     int rootindex=mp[root->val];
     int numlength=rootindex-instart;
     root->left=buildTree(preorder,prestart+1,prestart+numlength,inorder,instart,rootindex-1,mp);
     root->right=buildTree(preorder,prestart+numlength+1,preend,inorder,rootindex+1,inend,mp);
     return root;
    }
};