class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<pair<int, int>>& mapping,
             vector<int>& ans) {

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int index = 0;

        q.push({grid[0][0], {0, 0}});
        visited[0][0] = 1;

        int count = 0;

        for (auto [val, i] : mapping) {
            while (!q.empty() && q.top().first < val) {
                auto top = q.top();
                q.pop();

                count++;
                if (index < ans.size())
                    cout << mapping[index].first << " "
                         << ans[mapping[index].second] << endl;

                for (auto dir : directions) {
                    int x = top.second.first + dir.first;
                    int y = top.second.second + dir.second;

                    if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                        q.push({grid[x][y], {x, y}});
                        visited[x][y] = 1;
                    }
                }
            }
            ans[i]=count;
        }
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        vector<pair<int, int>> mapping;

        for (int i = 0; i < k; i++) {
            mapping.push_back({queries[i], i});
        }
        sort(mapping.begin(), mapping.end());

        for (auto pair : mapping) {
            cout << pair.first << " " << pair.second << endl;
        }
        cout << endl;
        vector<int> ans(k, 0);
        bfs(grid, mapping, ans);
        return ans;
    }
};