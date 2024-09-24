class Solution {
public:
    string minWindow(string s, string p) {
        vector<int> mp(128), curr(128); // Change size to 128 to handle all characters, not just lowercase letters
        int start = 0, len = INT_MAX, cnt = 0, n = s.size(), m = p.size();
        
        for (char ch : p)
            mp[ch]++; // Use ASCII values directly
        
        for (int i = 0, j = 0; j < n; j++) {
            cnt += curr[s[j]] < mp[s[j]]; // Increment count only if current char is needed
            curr[s[j]]++;
            
            while (i <= j && cnt == m) { // Check if the current window has all characters
                if (j - i + 1 < len) {
                    len = j - i + 1;
                    start = i;
                }
                cnt -= curr[s[i]] == mp[s[i]]; // Reduce the count if we are removing a necessary char
                curr[s[i]]--;
                i++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
