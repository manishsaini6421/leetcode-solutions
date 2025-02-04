class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum=nums[0],ans=0;
        int n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i-1]<nums[i]){
                maxSum+=nums[i];
            }
            else{
                ans=max(ans,maxSum);
                maxSum=nums[i];
            }
        }
        ans=max(ans,maxSum);
        return ans;
    }
};