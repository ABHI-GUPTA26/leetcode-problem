class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int start = 0, maxsize = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            // If character is already in the set, remove characters starting from `start` index
            while (st.find(s[i]) != st.end()) {
                st.erase(s[start]);
                start++;
            }
            // Add the current character to the set
            st.insert(s[i]);
            // Update maxsize if the current window is larger
            maxsize = max(maxsize, i - start + 1);
        }

        return maxsize;
    }
};
