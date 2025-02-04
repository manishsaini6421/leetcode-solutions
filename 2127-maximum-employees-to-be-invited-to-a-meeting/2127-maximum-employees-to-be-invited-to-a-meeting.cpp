class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        vector<int> dist(n, 0);
        vector<int> indegree(n, 0);
        int maxCycle = 0, twoLengthcycle = 0;

        for (int i = 0; i < n; i++) {
            indegree[favorite[i]]++;
            dist[i] = 1;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            int next = favorite[top];
            dist[next] = max(dist[next], dist[top] + 1);
            if (--indegree[next] == 0)
                q.push(next);
        }

        for (int i = 0; i < n; i++) {
            int cycleLength = 0;
            if (indegree[i]) {
                q.push(i);
                while (!q.empty()) {
                    auto top = q.front();
                    q.pop();
                    indegree[top] = 0;
                    cycleLength++;
                    int next = favorite[top];
                    if (indegree[next])
                        q.push(next);
                }
                if (cycleLength > 2) {
                    maxCycle = max(maxCycle, cycleLength);
                } else {
                    twoLengthcycle += dist[i] + dist[favorite[i]];
                }
            }
        }

        return max(maxCycle, twoLengthcycle);
    }
};