class DSU {

public:
    vector<int> Parent, Rank;

    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            Parent[i] = i;
    }

    int Find(int x) { return Parent[x] = Parent[x] == x ? x : Find(Parent[x]); }

    bool Union(int x, int y) {
        int rootX = Find(x), rootY = Find(y);

        if (rootX != rootY) {
            if (Rank[rootX] > Rank[rootY]) {
                Parent[rootY] = rootX;

            } else if (Rank[rootX] < Rank[rootY]) {
                Parent[rootX] = rootY;
            } else {
                Parent[rootY] = rootX;
                Rank[rootX]++;
            }

            return true;
        }
        return false;
    }
};
class Solution {

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            if (!dsu.Union(edges[i][0] - 1, edges[i][1] - 1))
                return edges[i];
        }

        return {};
    }
};