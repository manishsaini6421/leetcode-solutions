class Solution {
public:
    int coPrime(int a,int b){
        int n=min(a,b);
        for(int i=2; i<=n; i++){
            if(a%i==0 && b%i==0)return false;
        }
        return true;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        st.push(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(coPrime(st.top(),nums[i])==false){
                int temp=st.top();
                st.pop();
                st.push(lcm(temp,nums[i]));
            }
            else{
                st.push(nums[i]);
            }
        }
        vector<int> v(st.size(),0);
        while(! st.empty()){
            v[st.size()-1]=st.top();
            st.pop();
        }
        return v;
    }
};
