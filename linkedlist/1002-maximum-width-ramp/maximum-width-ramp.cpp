class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> stack;

        // First pass: build a decreasing stack
        for (int i = 0; i < n; ++i) {
            if (stack.empty() || nums[stack.back()] > nums[i]) {
                stack.push_back(i);
            }
        }

        int maxwidth = 0;

        // Second pass: iterate backwards and find the maximum width ramp
        for (int i = n - 1; i >= 0; --i) {
            while (!stack.empty() && nums[stack.back()] <= nums[i]) {
                maxwidth = max(maxwidth, i - stack.back());
                stack.pop_back();
            }
        }

        return maxwidth;
    }
};
