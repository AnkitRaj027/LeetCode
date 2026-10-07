class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m =matrix[0].size();
        int maxArea=0;
        vector<vector<int>> pSum(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=matrix[j][i]-'0';
                if(matrix[j][i]=='0'){sum=0;}
                pSum[j][i]=sum;
            }
        }
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,findHistogramRectangle(pSum[i]));
        }
        return maxArea;
    }
    int findHistogramRectangle(vector<int>& heights) {
        int n=heights.size();
        int maxArea=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
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