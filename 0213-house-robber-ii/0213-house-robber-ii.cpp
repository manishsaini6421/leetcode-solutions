class Solution {
public:
    int solve(vector<int> &nums){
        int n=nums.size();
        int prev1=nums[0],prev2=0;
        for(int i=1; i<n; i++){
            int curr=max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        vector<int> v1,v2;
        int n=nums.size();
        if(n==1)return nums[0];
        for(int i=0; i<n; i++){
            if(i!=n-1)v1.push_back(nums[i]);
            if(i!=0)v2.push_back(nums[i]);
        }
        return max(solve(v1),solve(v2));
    }
};