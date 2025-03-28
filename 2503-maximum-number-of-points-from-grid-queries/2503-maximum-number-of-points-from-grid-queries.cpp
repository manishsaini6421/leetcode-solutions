class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<pair<int, int>>& mapping, vector<int>& ans) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Min-heap (priority queue) to process cells in increasing order of value
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> q;
        
        // Start BFS from the top-left corner
        q.push({grid[0][0], {0, 0}});
        visited[0][0] = 1;

        int index = 0, count = 0;

        while (!q.empty() && index < mapping.size()) {
            int value = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();

            // If the grid value is less than the current query threshold
            while (index < mapping.size() && value >= mapping[index].first) {
                ans[mapping[index].second] = count;
                index++;
            }
            count++;

            // Explore all 4 directions
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    q.push({grid[nx][ny], {nx, ny}});
                    visited[nx][ny] = 1;
                }
            }
        }

        // Fill remaining answers (queries that couldn't be satisfied)
        while (index < mapping.size()) {
            ans[mapping[index].second] = count;
            index++;
        }
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        vector<pair<int, int>> mapping;

        for (int i = 0; i < k; i++) {
            mapping.push_back({queries[i], i});
        }
        sort(mapping.begin(), mapping.end());

        vector<int> ans(k, 0);
        bfs(grid, mapping, ans);
        return ans;
    }
};
