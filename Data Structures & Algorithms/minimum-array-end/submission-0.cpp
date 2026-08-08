class Solution {
public:
    long long minEnd(int n, int x) {
        // We must use long long because injecting bits into free slots 
        // will push the number well past the 32-bit integer limit.
        long long result = x;
        long long remaining = n - 1;
        
        // Iterate through up to 64 bit positions
        for (int i = 0; i < 64 && remaining > 0; ++i) {
            
            // Check if the i-th bit of 'result' is 0 (a free slot)
            // Note: 1LL ensures the '1' is a 64-bit integer before shifting
            if ((result & (1LL << i)) == 0) {
                
                // Extract the lowest bit of 'remaining'
                long long bit_to_inject = remaining & 1LL;
                
                // If the bit is 1, place it into the i-th slot of result
                result |= (bit_to_inject << i);
                
                // Shift 'remaining' right to prepare the next bit
                remaining >>= 1;
            }
        }
        
        return result;
    }
};