#define MOD 1000000007
class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;
        return (solve(n - 1,dp) *1l* 2 + solve(n - 3,dp))%MOD;
    }
    int numTilings(int n) {
        vector<int> dp(n,-1);
        return solve(n,dp);
    }
};