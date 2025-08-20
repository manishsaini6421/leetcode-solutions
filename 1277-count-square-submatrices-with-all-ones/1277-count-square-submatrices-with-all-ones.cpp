class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    int top = 0;
                    if (i > 0)
                        top = matrix[i - 1][j];
                    int left = 0;
                    if (j > 0)
                        left = matrix[i][j - 1];
                    int dig = 0;
                    if (i > 0 && j > 0)
                        dig = matrix[i - 1][j - 1];

                    matrix[i][j] += min(dig, min(left, top));
                    ans += matrix[i][j];
                }
            }
        }
        return ans;
    }
};