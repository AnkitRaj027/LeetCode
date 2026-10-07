class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxArea=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int el=st.top();
                st.pop();
                int nse=i;
                int pse= st.empty()?-1:st.top();
                maxArea=max(maxArea,heights[el]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int el=st.top();
            st.pop();
            int nse=n;
            int pse=st.empty()?-1:st.top();
            maxArea=max(maxArea,heights[el]*(nse-pse-1));
        }
        return maxArea;
    }
};