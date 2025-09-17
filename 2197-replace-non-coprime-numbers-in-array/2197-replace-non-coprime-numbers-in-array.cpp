class Solution {
public:
   
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        st.push(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(gcd(st.top(),nums[i])!=1){
                
                
                int temp1=st.top();
                st.pop();
               int temp2 = lcm(temp1,nums[i]);
               while(!st.empty() && gcd(st.top(),temp2)!=1){
                temp1=st.top();
                st.pop();
                temp2=lcm(temp1,temp2);
               } 
               st.push(temp2);
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
