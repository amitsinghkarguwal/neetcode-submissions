class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0;
        int index=0;
        int curr_tank=0;

        for(int i=0;i<gas.size();i++){

        
            curr_tank+=gas[i]-cost[i];

            total_gas+=gas[i]-cost[i];

            if(curr_tank<0){
                curr_tank=0;
                index=i+1;
            }

        }

        if(total_gas<0){
            return -1;
        }

        return index;
    }
};
