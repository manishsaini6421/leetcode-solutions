class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(), nums.end());
        map<int, int> dp;
        int temp=0;
        for (auto num : nums) {
            dp[num % space]++;
            if(temp<dp[num%space]) temp=dp[num%space];
        }
        int ans = INT_MAX;
        
        for (auto num : nums) {
            if (temp == dp[num % space]) {
                ans =min(ans,num);
            }
        }
        return ans;
    }
};