class Solution {
public:
    bool isValid(string x) {
        stack<char> st;
        int n = x.size();
        
        for(int i = 0; i < n; i++) {
            if(x[i] == '(' || x[i] == '{' || x[i] == '[') {
                st.push(x[i]);
            } else {
                // If the stack is empty or the top of the stack doesn't match
                if(st.empty()) return false;
                char ch = st.top();
                if((x[i] == ')' && ch == '(') || 
                   (x[i] == '}' && ch == '{') || 
                   (x[i] == ']' && ch == '[')) {
                    st.pop();  // Remove the matching bracket
                } else {
                    return false;
                }
            }
        }
        // If the stack is empty, brackets are balanced
        return st.empty();
    }
};