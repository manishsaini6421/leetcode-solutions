class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int count[3] = {0}; // count of 'a', 'b', and 'c'
        int left = 0;

        for (int right = 0; right < n; ++right) {
            count[s[right] - 'a']++;

            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                count[s[left] - 'a']--;
                left++;
            }

            // All substrings from [left-1..right] to [0..right] are valid
            ans += left;
        }
        return ans;
    }
};
