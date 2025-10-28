class Solution {
public:
    bool check(vector<int>& nums) {
        for (auto num : nums) {
            if (num)
                return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int curr = i;
                int dir = -1;
                vector<int> temp = nums;
                while (curr >= 0 && curr < n) {

                    if (temp[curr] > 0) {
                        temp[curr]--;
                        dir = -dir;
                    }
                    curr += dir;
                }
                if (check(temp)) {
                    ans++;
                }

                // right
                curr = i;
                temp = nums;
                dir = 1;
                while (curr >= 0 && curr < n) {

                    if (temp[curr] > 0) {
                        temp[curr]--;
                        dir = -dir;
                    }
                    curr += dir;
                }
                if (check(temp))
                    ans++;
            }
        }
        return ans;
    }
};