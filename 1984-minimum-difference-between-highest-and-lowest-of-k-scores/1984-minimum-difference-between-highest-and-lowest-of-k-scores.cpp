class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int j=k-1;
        int ans=INT_MAX;
        for(int i=0; i<=n-k; i++){
            ans=min(ans,nums[j]-nums[i]);
            j++;
        }
        return ans;
    }
};