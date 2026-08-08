#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; 
        
        for (int ast : asteroids) {
            bool destroyed = false;
            
            while (!st.empty() && st.back() > 0 && ast < 0) {
                
                // Case 1: Stack asteroid is smaller. It explodes.
                if (st.back() < abs(ast)) {
                    st.pop_back(); 
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
            
            if (!destroyed) {
                st.push_back(ast);
            }
        }
        
        return st;
    }
};