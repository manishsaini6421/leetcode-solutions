class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEle = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxEle + 1, 0);
        for (auto num : nums) {
            freq[num]++;
        }

        for (int i = 1; i <= maxEle; i++) {
            freq[i] += freq[i - 1];
        }
        int ans = 0;
        for (int target = 0; target <= maxEle; target++) {
            int left = max(0, target - k);
            int right = min(target + k, maxEle);

            int totalCount = freq[right] - (left > 0 ? freq[left - 1] : 0);
            int targetCount =
                freq[target] - (target > 0 ? freq[target - 1] : 0);
            int needConversion = totalCount - targetCount;

            int maxPossibleFreq =
                targetCount + min(needConversion, numOperations);
            ans = max(ans, maxPossibleFreq);
        }
        return ans;
    }
};