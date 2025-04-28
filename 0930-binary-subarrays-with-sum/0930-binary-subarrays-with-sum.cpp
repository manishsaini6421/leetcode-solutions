class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int> map;
        
        int sum=0;
        int ans=0;
        map[0]=1;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            ans+=map[sum-goal];
            map[sum]++;
            
        }
        return ans;
    }
};