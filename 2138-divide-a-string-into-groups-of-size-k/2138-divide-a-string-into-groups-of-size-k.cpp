class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();

        int j = 0;
        vector<string> ans;
        string temp = "";
        for (int i = 0; i < n; i++) {
            temp += s[i];
            j++;
            if (j == k) {
                ans.push_back(temp);
                j = 0;
                temp = "";
            }
        }
        if (j != 0) {
            while (j != k) {
                j++;
                temp += fill;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};