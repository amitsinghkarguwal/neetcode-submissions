class Solution {
public:
    bool isPalindrome(string s) {
        string result;

        for(auto c: s){
            if(isalnum(c)){
                result+=tolower(c);
            }
        }
        
        int i=0;
        int j=result.length()-1;
        while(i<j){
            
            if(result[i]!=result[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};
