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
public:  int maxsum(TreeNode*root,int &maxisum){
    if(root==nullptr)return 0;
    int ls=maxsum(root->left,maxisum);
    int rs=maxsum(root->right,maxisum);
    int both=ls+rs+root->val;
    int onlyone=max(ls,rs)+root->val;
    int noone=root->val;


    maxisum=max({maxisum,both,onlyone,noone});
    return max(onlyone,noone);
}
    int maxPathSum(TreeNode* root) {
        int maxisum=INT_MIN;
        maxsum(root,maxisum);
        return maxisum;
    }
};