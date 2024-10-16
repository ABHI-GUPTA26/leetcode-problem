class Solution {
public:
    void solve(int index, string& s, int n, vector<string>& res) {
        if (index == n) {
            res.push_back(s);
            return;
        }
        if (isdigit(s[index])) {
            solve(index + 1, s, n, res);
        } else {
            s[index] = toupper(s[index]);
            solve(index + 1, s, n, res);
            s[index] = tolower(s[index]);
            solve(index + 1, s, n, res);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        solve(0, s, s.size(), res);
        return res;
    }
};