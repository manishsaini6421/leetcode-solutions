#define MOD 1000000007
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        stack<int> st;
        int temp=1;
        while(temp<n){
            temp*=2;
        }

        while(temp){
            if(temp<=n){
                st.push(temp);
                n-=temp;
            }
            temp/=2;
            
        }
        while(!st.empty()){
            powers.push_back(st.top());
            st.pop();
        }
        vector<int> ans;
        int size=queries.size();

        for(int i=0; i<size; i++){
            int x=1;
            for(int j=queries[i][0]; j<=queries[i][1]; j++){
                x=(x*1l*powers[j])%MOD;
            }
            ans.push_back(x);
        }
        return ans;
    }
};