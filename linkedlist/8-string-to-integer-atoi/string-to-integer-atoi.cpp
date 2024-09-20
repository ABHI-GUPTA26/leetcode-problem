class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int sign = 1; // Default to positive
        long long num = 0; // Use long long to handle overflow

        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Handle optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            num = num * 10 + digit;

            // Step 4: Check for overflow/underflow
            if (num > INT_MAX) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            i++;
        }

        return sign * num; // Apply the sign to the result
    }
};
