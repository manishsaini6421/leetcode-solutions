class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max=0;
        for(auto num:nums){
            if(max<num)max=num;
        }
        int ans=0,temp=0;
        for(auto num:nums){
            if(max==num)temp++;
            else temp=0;
            if(temp>ans)ans=temp;

        }
        return ans;
    }
};