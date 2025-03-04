class Solution {
public:
    int solve(vector<int> &nums,int i){
        if(i>=nums.size())return 0;
        return max(nums[i]+solve(nums,i+2),solve(nums,i+1));
    }
    int rob(vector<int>& nums) {
        return solve(nums,0);
    }
};