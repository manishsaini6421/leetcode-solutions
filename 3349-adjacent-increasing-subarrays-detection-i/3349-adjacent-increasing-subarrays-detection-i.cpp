class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> temp(n,0);
        temp[0]=1;
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1])temp[i]=temp[i-1]+1;
            else temp[i]=1;
        }
        for(int i=0; i<n-k; i++){
            if(temp[i]>=k && temp[i+k]>=k)return true;
        }
        return false;
    }
};