
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m));
        queue<pair<int, pair<int, int>>> q;

        const int drow[4] = {1, 0, -1, 0};
        const int dcol[4] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            auto [steps, cell] = q.front();
            auto [row, col] = cell;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    ans[nrow][ncol] = steps + 1;
                    q.push({steps + 1, {nrow, ncol}});
                }
            }
        }

        return ans;
    }
};
