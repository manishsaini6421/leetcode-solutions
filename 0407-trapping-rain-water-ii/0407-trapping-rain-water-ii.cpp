class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0; // Handle edge case for empty input
        int n = heightMap[0].size();
        if (n == 0) return 0; // Handle edge case for empty input

        // Priority queue to hold {height, row, col} of boundary cells
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Visited matrix to mark processed cells
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // Add boundary cells to the priority queue
        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], i, 0});       // Left boundary
            pq.push({heightMap[i][n - 1], i, n - 1}); // Right boundary
            visited[i][0] = visited[i][n - 1] = 1; // Mark visited
        }
        for (int j = 0; j < n; ++j) {
            pq.push({heightMap[0][j], 0, j});       // Top boundary
            pq.push({heightMap[m - 1][j], m - 1, j}); // Bottom boundary
            visited[0][j] = visited[m - 1][j] = 1; // Mark visited
        }

        // Directions for moving to neighbors
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int waterTrapped = 0;

        // Process cells in the priority queue
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();

            int height = cell[0]; // Current cell's height
            int x = cell[1];
            int y = cell[2];

            // Explore all 4 neighbors
            for (auto& dir : directions) {
                int nx = x + dir.first; // New row
                int ny = y + dir.second; // New col

                // Skip invalid or already visited cells
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) 
                    continue;

                visited[nx][ny] = 1; // Mark neighbor as visited
                // Calculate trapped water for the neighbor
                waterTrapped += max(0, height - heightMap[nx][ny]);
                // Add the neighbor to the queue with the updated height
                pq.push({max(height, heightMap[nx][ny]), nx, ny});
            }
        }

        return waterTrapped;
    }
};
