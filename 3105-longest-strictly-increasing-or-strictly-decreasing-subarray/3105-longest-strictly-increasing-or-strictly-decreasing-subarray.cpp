class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int inclength=1;
        int declength=1;
        for(int i=1; i<n; i++){
            if(nums[i-1]<nums[i]){
                inclength++;
                ans=max(ans,inclength);
                declength=1;
            }
            else if(nums[i-1]>nums[i]){
                declength++;
                ans=max(ans,declength);
                inclength=1;
            }
            else{
                inclength=1;
                declength=1;
            }
        }
        return ans;
    }
};