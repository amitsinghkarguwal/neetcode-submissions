class Solution {
public:
    int calPoints(vector<string>& operations) {
       stack<int> s;
       for(auto i: operations){
        if(i=="+"){
            int a=s.top();
            s.pop();
            int b=s.top();
            int c=a+b;
            s.push(a);
            s.push(c);
        }
        else if(i=="D"){
            int m=s.top();
            s.push(2*m);
        }
        else if(i=="C"){
            s.pop();
        }
        else{
            s.push(stoi(i));
        }
       } 

       int sum=0;
       while(!s.empty()){
        sum+=s.top();
        s.pop();
       }

       return sum;
    }
};