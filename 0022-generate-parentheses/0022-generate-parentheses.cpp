class Solution {
public:
    void gen(vector<string>& ans, int n, string s, int open, int close) {

        if (open < close)
            return;
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            gen(ans, n, s + '(', open + 1, close);
        }
        if (close < n) {

            gen(ans, n, s + ')', open, close + 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(ans, n, "", 0, 0);

        return ans;
    }
};