class Solution {
public:
    int count = 0;
    string ans = "";
    void solve(int k, int n, string s) {
        if (s.size() == n) {
            count++;

            if (count == k) {
                ans = s;
                
            }
            return;
        }

        if (s.size()==0 || s[s.size() - 1] != 'a')
            solve(k, n, s + 'a');
        if (s.size()==0 || s[s.size() - 1] != 'b')
            solve(k, n, s + 'b');
        if (s.size()==0 || s[s.size() - 1] != 'c')
            solve(k, n, s + 'c');
    }
    string getHappyString(int n, int k) {
        int pos = 3 * pow(2, n - 1);
        if (pos < k)
            return "";
        solve(k, n, "");
        return ans;
    }
};