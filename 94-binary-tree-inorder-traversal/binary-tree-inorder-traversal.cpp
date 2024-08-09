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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        while(root!=nullptr){
   if(root->left==nullptr){
         inorder.push_back(root->val);
         root=root->right;
   }else{
    TreeNode*pre=root->left;
       while(pre->right&&pre->right!=root){
        pre=pre->right;
       }
       if(pre->right==root){
        pre->right=nullptr;
        inorder.push_back(root->val);
        root=root->right;

       }else{
        pre->right=root;
        root=root->left;
       }
   }
   
        }
        return inorder;
    }
};