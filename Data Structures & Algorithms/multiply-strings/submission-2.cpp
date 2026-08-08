class Solution {
public:
    string multiply(string num1, string num2) {


        vector<int> v1,v2;

        for(int i = num1.size() - 1; i >= 0; i--){
            v1.push_back(num1[i] - '0');
        }
        for(int i = num2.size() - 1; i >= 0; i--){
            v2.push_back(num2[i] - '0');
        }

        vector<int> result(v1.size()+v2.size(), 0);

        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                int multiple=v1[i]*v2[j]+result[i+j];

                result[i+j]=(multiple)%10;
                result[i+j+1]+=(multiple)/10;
            }
        }

        while(result.size() > 1 && result.back() == 0){
            result.pop_back();
        }

        string res;

        for(auto i : result){
            res=to_string(i)+res;
        }

        return res;


        
        

    }
};
