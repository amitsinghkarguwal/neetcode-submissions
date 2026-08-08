class Solution {
public:
    bool isPalindrome(string s) {
        string result;

        for(auto c: s){
            if(isalnum(c)){
                result+=tolower(c);
            }
        }

        string res=result;
        reverse(result.begin(), result.end());
        return result==res;
    }
};
