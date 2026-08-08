#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token : tokens) {
            // If the token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                
                // Pop the top two elements. 
                // ORDER MATTERS: The first popped is the SECOND operand.
                int num2 = st.top(); 
                st.pop();
                int num1 = st.top(); 
                st.pop();
                
                // Perform the operation and push the result
                if (token == "+") st.push(num1 + num2);
                else if (token == "-") st.push(num1 - num2);
                else if (token == "*") st.push(num1 * num2);
                else if (token == "/") st.push(num1 / num2);
                
            } 
            // If the token is a number
            else {
                st.push(stoi(token));
            }
        }
        
        // The final result is the only item left in the stack
        return st.top();
    }
};