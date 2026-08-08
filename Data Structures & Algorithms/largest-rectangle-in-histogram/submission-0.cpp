class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

      stack<pair<int,int>> st;
      int max_size=0;
      st.push({0, heights[0]});


      for(int i=1;i<heights.size();i++){


        int back_index=i;

        while(!st.empty() && heights[i]<st.top().second ){

            int index=st.top().first;
            back_index=index;
            int num=st.top().second;
            st.pop();

            int area=num*(i-index);
            max_size=max(area, max_size);
        }

        st.push({back_index, heights[i]});

      }  


      while(!st.empty()){
            int index=st.top().first;
            int num=st.top().second;
            st.pop();

            int area=num*(heights.size()-index);
            max_size=max(area, max_size);
      }


      return max_size;



    }
};
