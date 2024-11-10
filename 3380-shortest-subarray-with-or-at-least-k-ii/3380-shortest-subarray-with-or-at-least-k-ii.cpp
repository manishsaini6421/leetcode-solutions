class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> v(32, 0);
        int n = nums.size();
        int i=0,j = 0;
        int ans = INT_MAX;
        int num = 0;

        while (j < n) {
            int x = nums[j];
            int index = 0;
            while (x) {
                if (x & 1)
                    v[index]++;
                index++;
                x >>= 1;
            }
            num = 0;
            for (int idx = 0; idx < 32; idx++) {
                if (v[idx]) num |= (1 << idx);
                
            }
            while (num >= k && i <= j) {
                ans = min(ans, j - i + 1);
                int y = nums[i];
                int idx = 0;
                while (y) {
                    if (y & 1)
                        v[idx]--;
                    idx++;
                    y >>= 1;
                }
                i++;
                num = 0;
                for (int idx = 0; idx < 32; idx++) {
                    if (v[idx]) num |= (1 << idx);
                    
                }
            }
            j++;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};