class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_occurance;

        //filling up the map with the last occurance of the element;
        for(int i=s.length()-1;i>=0;i--){
            if(!last_occurance.count(s[i])){
                last_occurance[s[i]]=i;
            }
        }

        int partition_start=0;
        int partition_end=-1;
        vector<int> result;

        for(int i=0;i<s.length();i++){
            partition_end=max(partition_end, last_occurance[s[i]]);

            if(partition_end==i){
                result.push_back(partition_end-partition_start+1);

                if(!(i==s.length()-1)){
                    partition_start=i+1;
                }

            }
        }

        return result;


    }
};
