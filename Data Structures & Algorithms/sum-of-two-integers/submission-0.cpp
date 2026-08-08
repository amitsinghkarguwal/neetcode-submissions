class Solution {
public:
    int getSum(int a, int b) {
        // Loop until there is no carry left to add
        while (b != 0) {
            
            // Step 1: Calculate the carry.
            // In C++, left-shifting a negative signed integer is Undefined Behavior.
            // We MUST cast (a & b) to unsigned int before shifting it.
            unsigned int carry = (unsigned int)(a & b) << 1;
            
            // Step 2: Calculate the raw sum (ignoring the carry)
            a = a ^ b;
            
            // Step 3: Move the carry into 'b' so we can add it in the next loop
            b = carry;
        }
        
        // When 'b' reaches 0, 'a' contains the final, complete sum.
        return a;
    }
};