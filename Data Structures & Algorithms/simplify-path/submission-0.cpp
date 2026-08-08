#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {

        vector<string> st;
        
        // Stringstream allows us to easily parse the string by a delimiter
        stringstream ss(path);
        string token;
        
        // getline(ss, token, '/') extracts text up to the next '/', 
        // storing it in 'token' and discarding the '/'
        while (getline(ss, token, '/')) {
            
            // Ignore empty tokens (caused by "//") and current directory "."
            if (token == "" || token == ".") {
                continue;
            } 
            // ".." means go up a directory. Pop the stack if possible.
            else if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } 
            // It's a valid directory name. Push it.
            else {
                st.push_back(token);
            }
        }
        
        // Rebuild the final path
        string result = "";
        for (const string& dir : st) {
            result += "/" + dir;
        }
        
        // If the stack was completely emptied (e.g. "/../"), return root "/"
        return result.empty() ? "/" : result;
    }
};