#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {\
        int fives = 0;
        int tens = 0;
        
        for (int bill : bills) {
            if (bill == 5) {
                fives++;
            } 
            else if (bill == 10) {
                if (fives == 0) {
                    return false; // Bankrupt!
                }
                fives--;
                tens++; // We keep their $10
            } 
            else if (bill == 20) {
                // Customer gives $20. We owe $15 in change.
                
                // GREEDY STRATEGY: Get rid of $10s first because they are less versatile.
                if (tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                } 
                // FALLBACK: If we have no $10s, we must use three $5s.
                else if (fives >= 3) {
                    fives -= 3;
                } 
                // If neither option is possible, we can't make change.
                else {
                    return false;
                }
            }
        }
        
        // If the loop finishes, every customer was served successfully!
        return true;
    }
};