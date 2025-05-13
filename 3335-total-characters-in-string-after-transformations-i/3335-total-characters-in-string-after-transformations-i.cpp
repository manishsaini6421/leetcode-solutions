#define MOD 1000000007
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> arr(26, 0);
        vector<int> brr(26, 0);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            arr[s[i] - 'a']++;
        }
        
        for (int i = 0; i < t; i++) {
            fill(brr.begin(), brr.end(), 0);

            for (int j = 0; j < 26; j++) {

                if (j == 25) {
                    brr[0] = (brr[0] + arr[25]) % MOD;
                    brr[1] = (brr[1] + arr[25]) % MOD;
                } else {
                    brr[j + 1] = (brr[j + 1] + arr[j]) % MOD;
                }
            }
            arr = brr;
           
        }
        int ans = 0;
        for (int j = 0; j < 26; j++) {
            ans = (ans + arr[j]) % MOD;
        }
        return ans;
    }
};