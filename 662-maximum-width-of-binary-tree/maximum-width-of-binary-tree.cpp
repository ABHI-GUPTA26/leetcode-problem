class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0; // Check for an empty tree

        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            unsigned long long start = q.front().second; // The leftmost node index at the current level
            unsigned long long end = q.back().second; // The rightmost node index at the current level
            maxWidth = max(maxWidth, int(end - start + 1)); // Calculate the width for the current level

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

        return maxWidth;
    }
};
