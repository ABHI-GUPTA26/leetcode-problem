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
public:  void solve(TreeNode*root,TreeNode* temp ){
    int val=temp->val;
        if(val<root->val){
            if(root->left){
                solve(root->left,temp);
            }
            else
            root->left=temp;
        }
        else{
             if(root->right){
                solve(root->right,temp);
            }
            else
            root->right=temp;
            
        }
}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) return new TreeNode(val);
        TreeNode*temp=new TreeNode(val);
          solve(root,temp);
          return root;
    }
};