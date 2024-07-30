class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;  // Use long long to handle the edge case where n is INT_MIN
        if (nn < 0) {
            nn = -nn;
        }
        while (nn) {
            if (nn % 2) {
                ans *= x;
                nn -= 1;
            } else {
                x *= x;
                nn /= 2;
            }
        }
        if (n < 0) {
            ans = 1.0 / ans;
        }
        return ans;
    }
};
