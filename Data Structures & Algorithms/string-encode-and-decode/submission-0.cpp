class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto i: strs){
            int n=i.length();
            s=s+to_string(n)+'#'+i;
        }
        return s;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> result;
        while(i<s.length()){
            int pos=s.find('#',i);
            int length=stoi(s.substr(i, pos-i));
            result.push_back(s.substr(pos+1,length));
            i=length+pos+1;
        }

        return result;

    }
};
