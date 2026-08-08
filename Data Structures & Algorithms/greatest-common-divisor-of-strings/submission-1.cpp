#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Step 1: Check if a common divisor is even possible
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // Step 2: Calculate the GCD of the two string lengths
        int gcd_length = gcd(str1.length(), str2.length());
        
        // Step 3: Return the prefix of that exact length
        return str1.substr(0, gcd_length);
    }
};