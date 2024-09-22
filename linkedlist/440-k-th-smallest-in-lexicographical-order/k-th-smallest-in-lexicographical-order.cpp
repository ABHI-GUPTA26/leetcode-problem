class Solution {
public:
    // Function to calculate how many numbers exist between the current prefix and n
    int countSteps(int current, long n) {
        long steps = 0;
        long first = current;
        long last = current;
        
        // Count how many numbers there are between [first, last] within the range [1, n]
        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        
        return steps;
    }

    int findKthNumber(int n, int k) {
        int current = 1;  // Start with 1
        k--;  // Decrement k because we consider the first number is "1"

        while (k > 0) {
            int steps = countSteps(current, n);  // Count how many numbers are in the subtree of `current`

            if (steps <= k) {
                // If k is greater than or equal to the numbers in this subtree, skip this subtree
                current++;
                k -= steps;
            } else {
                // Otherwise, go deeper into the subtree
                current *= 10;
                k--;
            }
        }

        return current;
    }
};
