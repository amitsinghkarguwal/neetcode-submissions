class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==']' || s[i]=='}' || s[i]==')'){
                if(st.empty()) return false;
                else if(st.top()=='[' && s[i]==']') st.pop();
                else if(st.top()=='{' && s[i]=='}') st.pop();
                else if(st.top()=='(' && s[i]==')') st.pop();
                else return false;
            }
            else st.push(s[i]);
        }

        if(st.empty()) return true;
        else return false;
    }
};