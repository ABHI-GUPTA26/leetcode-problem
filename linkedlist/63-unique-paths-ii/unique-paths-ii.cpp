class Solution {
public:
    int solve(vector<vector<int>>& Grid, int row, int col, vector<vector<int>>& dp) {
        if (row >= 0 && col >= 0 && Grid[row][col] == 1) return 0;
        if (row == 0 && col == 0) return 1;
        if (row < 0 || col < 0) return 0;
        if (dp[row][col] != -1) return dp[row][col];
        int up = solve(Grid, row - 1, col, dp);
        int left = solve(Grid, row, col - 1, dp);
        return dp[row][col] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n = Grid.size();
        int m = Grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(Grid, n - 1, m - 1, dp);
    }
};