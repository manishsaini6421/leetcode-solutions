class Solution {
public:
    int solve(vector<int>& obstacles, int i, int lane) {
        if (i == obstacles.size() - 1)
            return 0;

        if (lane != obstacles[i + 1]) {
            return solve(obstacles, i + 1, lane);
        }

        int ans = INT_MAX;
        if (lane == 1) {
            if (obstacles[i] != 2)
                ans = min(ans, 1 + solve(obstacles, i, 2));
            if (obstacles[i] != 3)
                ans = min(ans, 1 + solve(obstacles, i, 3));
        } else if (lane == 2) {
            if (obstacles[i] != 1)
                ans = min(ans, 1 + solve(obstacles, i, 1));
            if (obstacles[i] != 3)
                ans = min(ans, 1 + solve(obstacles, i, 3));
        } else if (lane == 3) {
            if (obstacles[i] != 1)
                ans = min(ans, 1 + solve(obstacles, i, 1));
            if (obstacles[i] != 2)
                ans = min(ans, 1 + solve(obstacles, i, 2));
        }
        return ans;
    }
    int minSideJumps(vector<int>& obstacles) { 
        
        return solve(obstacles, 0, 2); 
        }
};