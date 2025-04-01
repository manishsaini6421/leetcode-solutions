class Solution {
public:
    int search(vector<int>& stones, int x, int i, int j) {
        int mid;
        while (i <= j) {
            mid = i + (j - i) / 2;
            if (stones[mid] == x)
                return mid;
            else if (stones[mid] > x) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return -1;
    }
    bool solve(vector<int>& stones, int index, int k) {
        int n = stones.size();
        if (index == n - 1)
            return true;
        bool first = false;
        int idx1 = search(stones, stones[index] + k - 1, index, n - 1);
        if (k - 1 > 0 && idx1 != -1) {
            first = solve(stones, idx1, k - 1);
        }
        bool second = false;
        int idx2 = search(stones, stones[index] + k, index, n - 1);
        if (idx2 != -1) {
            second = solve(stones, idx2, k);
        }
        bool third = false;
        int idx3 = search(stones, stones[index] + k + 1, index, n - 1);
        if (idx3 != -1) {
            third = solve(stones, idx3, k + 1);
        }
        return first || second || third;
    }
    bool solveMem(vector<int>& stones, int index, int k,
                  vector<vector<int>>& dp) {
        int n = stones.size();
        if (index == n - 1)
            return true;

        if (dp[index][k] != -1)
            return dp[index][k];
        bool first = false;
        int idx1 = search(stones, stones[index] + k - 1, index, n - 1);
        if (k - 1 > 0 && idx1 != -1) {
            first = solveMem(stones, idx1, k - 1, dp);
        }
        bool second = false;
        int idx2 = search(stones, stones[index] + k, index, n - 1);
        if (idx2 != -1) {
            second = solveMem(stones, idx2, k, dp);
        }
        bool third = false;
        int idx3 = search(stones, stones[index] + k + 1, index, n - 1);
        if (idx3 != -1) {
            third = solveMem(stones, idx3, k + 1, dp);
        }
        return dp[index][k] = (first || second || third);
    }

    bool solveTab(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            map[stones[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = 1;
        }
        for (int index = n - 2; index >= 1; index--) {
            for (int k = n - 2; k >= 1; k--) {
                bool first = false;
                int idx1 = map.count(stones[index] + k - 1)
                               ? map[stones[index] + k - 1]
                               : -1;
                if (k - 1 > 0 && idx1 !=-1) {
                    first = dp[idx1][k - 1];
                }
                bool second = false;
                int idx2 =
                    map.count(stones[index] + k) ? map[stones[index] + k] : -1;
                if (idx2 != -1) {
                    second = dp[idx2][k];
                }
                bool third = false;
                int idx3 = map.count(stones[index] + k + 1)
                               ? map[stones[index] + k + 1]
                               : -1;
                if (idx3 != -1) {
                    third = dp[idx3][k + 1];
                }
                dp[index][k] = (first || second || third);
            }
        }
        return dp[1][1];
    }
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1)
            return false;
        // return solve(stones,1,1);

        // int n = stones.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveMem(stones, 1, 1, dp);

        return solveTab(stones);
    }
};