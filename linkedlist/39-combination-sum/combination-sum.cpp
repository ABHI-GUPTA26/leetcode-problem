class Solution {
public:
    void solve(vector<int>& arr, int target, int ind, vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (ind >= arr.size() || target < 0) {
            return;
        }
        solve(arr, target, ind + 1, temp, ans);
        if (arr[ind] <= target) {
            temp.push_back(arr[ind]);
            solve(arr, target - arr[ind], ind, temp, ans);
            temp.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, 0, temp, ans);
        return ans;
    }
};