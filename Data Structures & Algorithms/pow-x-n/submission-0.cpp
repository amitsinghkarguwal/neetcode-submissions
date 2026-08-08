class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; // Use long long to prevent INT_MIN overflow
        
        // Handle negative exponents
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1.0;
        double current_product = x;
        
        while (N > 0) {
            // If the current bit of the exponent is 1 (odd number)
            if (N % 2 == 1) {
                ans *= current_product;
            }
            // Square the base for the next bit position
            current_product *= current_product;
            // Shift down the exponent by dividing by 2
            N /= 2;
        }
        
        return ans;
    }
};

