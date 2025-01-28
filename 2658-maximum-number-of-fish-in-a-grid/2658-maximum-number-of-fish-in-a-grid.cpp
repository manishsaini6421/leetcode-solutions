class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    stack<pair<int, int>> s;
                    s.push({i, j});
                    visited[i][j] = 1;
                    int sum = 0;
                    while (!s.empty()) {
                        auto top = s.top();
                        sum += grid[top.first][top.second];
                        s.pop();
                        for (auto [x, y] : directions) {
                            int nx = top.first + x;
                            int ny = top.second + y;

                            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                                !visited[nx][ny] && grid[nx][ny] > 0) {
                                s.push({nx, ny});
                                visited[nx][ny] = 1;
                            }
                        }
                    }
                    ans = max(ans, sum);
                }
            }
        }

        return ans;
    }
};