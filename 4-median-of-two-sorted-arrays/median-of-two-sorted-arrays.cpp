class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                nums.push_back(nums1[i++]);
            } else {
                nums.push_back(nums2[j++]);
            }
        }

        while (i < n) {
            nums.push_back(nums1[i++]);
        }

        while (j < m) {
            nums.push_back(nums2[j++]);
        }

        int totalSize = n + m;
        if (totalSize % 2 == 0) {
            return (nums[totalSize / 2 - 1] + nums[totalSize / 2]) / 2.0;
        } else {
            return nums[totalSize / 2];
        }
    }
};
