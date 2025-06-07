class Solution {
public:
    bool solveMem(vector<int>& nums,int index,vector<int> &dp){
        if(index==nums.size()-1)return true;
        if(index>=nums.size())return false;

        if(dp[index]!=-1)return dp[index];
        bool ans=false;

        for(int i=1; i<=nums[index]; i++){
            bool temp=solveMem(nums,index+i,dp);
            if(temp)return dp[index]=true;
            ans|=temp;
        }
        return dp[index]=ans;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solveMem(nums,0,dp);
    }
};