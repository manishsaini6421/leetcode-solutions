class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long temp = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                temp++;
            else {
                ans += (temp * (temp + 1)) / 2;
                temp = 0;
            }
        }
        ans += (temp * (temp + 1)) / 2;
        return ans;
    }
};