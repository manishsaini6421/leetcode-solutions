class Solution {
public:
    int solve(vector<int>& nums,int target,int index){
        if(index<0){
            if(target==0)return 1;
            else return 0;
        }

        return solve(nums,target+nums[index],index-1)+solve(nums,target-nums[index],index-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(nums,target,n-1);
    }
};