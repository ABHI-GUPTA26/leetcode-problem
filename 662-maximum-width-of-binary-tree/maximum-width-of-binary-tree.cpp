class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxwidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = q.back().second;
            maxwidth = max(maxwidth, int(right - left + 1));
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                unsigned long long col = q.front().second;
                q.pop();
                
                if (node->left) {
                    q.push({node->left, 2 * col});
                }
                if (node->right) {
                    q.push({node->right, 2 * col + 1});
                }
            }
        }
        return maxwidth;
    }
};
