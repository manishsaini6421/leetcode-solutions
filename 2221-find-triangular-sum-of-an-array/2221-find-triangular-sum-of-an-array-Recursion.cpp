class Solution {
public:
    
    int triangularSum(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int> v;
        int n=nums.size();
        for(int i=1; i<n; i++){
            v.push_back((nums[i]+nums[i-1])%10);
        }
        return triangularSum(v);
    }
};