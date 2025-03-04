class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prevSum=0,currSum=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            
            currSum=max(nums[i],currSum+nums[i]);
            prevSum=max(prevSum,currSum);
        }
        return prevSum;
    }
};