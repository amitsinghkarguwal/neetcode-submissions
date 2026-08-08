#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string result = "";


        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            // If 'i' is still inside string 'a', add its integer value to sum
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            // If 'j' is still inside string 'b', add its integer value to sum
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            result += to_string(sum % 2);

            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        
        return result;
    }
};