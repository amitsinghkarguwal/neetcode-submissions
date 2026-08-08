class Solution {
private:
    // Helper function to calculate the sum of the squares of digits
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int digit = n % 10;
            totalSum += digit * digit;
            n /= 10;
        }
        return totalSum;
    }

public:
    // Renamed to 'isHappy' to match the expected testing signature
    bool isHappy(int n) {
        // Initialize slow and fast pointers
        int slow = n;
        int fast = getNext(n);
        
        // Loop until fast reaches 1 (Happy/Non-Cyclical) or the pointers meet (Cyclical)
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);                // Move slow 1 step
            fast = getNext(getNext(fast));       // Move fast 2 steps
        }
        
        // If fast broke the loop by reaching 1, it's a happy number
        return fast == 1;
    }
};