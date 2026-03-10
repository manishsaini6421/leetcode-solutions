class Solution {
public:
    int MOD = 1000000007;
    int solve(int zero, int one, bool lastOne, int limit,
              vector<vector<vector<int>>>& dp) {
        if (zero == 0 && one == 0)
            return 1;

        if (dp[zero][one][lastOne] != -1)
            return dp[zero][one][lastOne];
        long long ans = 0;
        if (lastOne) {
            for (int i = 1; i <= min(zero, limit); i++) {
                ans = (ans + solve(zero - i, one, false, limit, dp)) % MOD;
            }
        } else {
            for (int i = 1; i <= min(one, limit); i++) {
                ans = (ans + solve(zero, one - i, true, limit, dp)) % MOD;
            }
        }
        return dp[zero][one][lastOne] = (ans % MOD);
    }

    int solveMem(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(
            zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));
        dp[0][0][1] = 1;
        dp[0][0][0] = 1;

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                
                    if(i==0 && j==0)continue;
                    long long ans = 0;
                    
                        for (int k = 1; k <= min(i, limit); k++) {
                            dp[i][j][1] = (dp[i][j][1] + dp[i - k][j][0]) % MOD;
                        }
                   
                        for (int k = 1; k <= min(j, limit); k++) {
                            dp[i][j][0] = (dp[i][j][0] + dp[i][j - k][1]) % MOD;
                        }
                    
                    
                
            }
        }
        return (dp[zero][one][0]+dp[zero][one][1])%MOD;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        // vector<vector<vector<int>>> dp(
        //     zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));

        // return (solve(zero, one, false, limit, dp) + 0l +
        //         solve(zero, one, true, limit, dp)) %
        //        MOD;

        return solveMem(zero,one,limit);
    }
};