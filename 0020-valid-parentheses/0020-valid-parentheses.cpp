class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> st;
        if(n==1)return false;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }else{
                if(st.empty())return false;
                char t=st.top();
                st.pop();
                if(s[i]==')' && t!='(')return false;
                else if(s[i]==']' && t!='[')return false;
                else if(s[i]=='}' && t!='{')return false;
                
            }
        }
        if(st.empty())return true;
        else return false;
    }
};