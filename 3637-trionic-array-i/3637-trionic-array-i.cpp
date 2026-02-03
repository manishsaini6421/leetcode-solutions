class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]>=nums[1])return false;
        int i=1;
        while(nums[i]>nums[i-1]){
            if(i==n-1)return false;
            i++;
        }
        while(nums[i]<nums[i-1]){
            if(i==n-1)return false;
            i++;
        }
        while(i<n){
        
            if(nums[i]<=nums[i-1])return false;
            i++;
        }
        return true;
    }
};