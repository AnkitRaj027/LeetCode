class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=findNSE(arr);
        vector<int> psee=findPSEE(arr);
        int n=arr.size();
        long long total=0;
        int mod=(int)1e9+7;
        for(int i=0;i<n;i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            total= (total+ (1LL*arr[i]*left*right)%mod)%mod;
        }
        return total;
    }
    vector<int> findNSE(vector<int>arr){
        int n=arr.size();
        vector<int> ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>findPSEE(vector<int>arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans; 
    }
};