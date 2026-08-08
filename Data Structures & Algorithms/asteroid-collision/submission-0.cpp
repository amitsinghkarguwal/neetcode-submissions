#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // We use a vector to simulate the stack so we can return it directly at the end.
        vector<int> st; 
        
        for (int ast : asteroids) {
            bool destroyed = false;
            
            // A collision ONLY happens if:
            // 1. There is an asteroid in the stack.
            // 2. The asteroid at the top is moving RIGHT (> 0).
            // 3. The current asteroid is moving LEFT (< 0).
            while (!st.empty() && st.back() > 0 && ast < 0) {
                
                // Case 1: Stack asteroid is smaller. It explodes.
                if (st.back() < abs(ast)) {
                    st.pop_back(); 
                    // Continue the while loop to check the next asteroid in the stack!
                    continue; 
                } 
                // Case 2: They are the same size. Both explode.
                else if (st.back() == abs(ast)) {
                    st.pop_back(); 
                    destroyed = true;
                    break; 
                } 
                // Case 3: Stack asteroid is larger. Current asteroid explodes.
                else {
                    destroyed = true;
                    break;
                }
            }
            
            // If the current asteroid survived all collisions, add it to the stack
            if (!destroyed) {
                st.push_back(ast);
            }
        }
        
        return st;
    }
};