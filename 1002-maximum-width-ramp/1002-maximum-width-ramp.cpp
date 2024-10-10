class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
       for(int i=0; i<nums.size(); i++){
            if(st.empty() || nums[i]<nums[st.top()]){
                st.push(i);
            }
       }
       int res=0;
       for(int i=nums.size()-1; (!st.empty()&&i>=0); i--){
            while(!st.empty() && nums[i]>=nums[st.top()]){
                res=max(res,i-st.top());
                st.pop();

            }
       }
      
       return res;
    }
};