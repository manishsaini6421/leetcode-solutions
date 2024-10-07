class Solution {
public:
    int minLength(string s) {
        stack<int> st;
        int i=0;
        while(i<s.size()){
            if(!st.empty() && ((st.top()=='A' && s[i]=='B') || (st.top()=='C' && s[i]=='D')))st.pop();
            else st.push(s[i]);
            
           i++;
        }
        return st.size();
    }
};