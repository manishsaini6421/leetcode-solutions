class Solution {
public:
    void minutePossibilities(vector<vector<int>>& min, int idx, int cnt,
                             int total) {
        if (idx == 6) {
            if (cnt != 0 && total < 60)
                min[cnt].push_back(total);
            return;
        }
        if (total > 59)
            return;

        minutePossibilities(min, idx + 1, cnt + 1, total + pow(2, idx));
        minutePossibilities(min, idx + 1, cnt, total);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        if (turnedOn > 8)
            return ans;
        vector<vector<int>> hrs = {
            {0}, {1, 2, 4, 8}, {3, 5, 9, 6, 10}, {7, 11}};
        vector<vector<int>> min(7);
        min[0] = {0};

        minutePossibilities(min, 0, 0, 0);

        for (int i = 0; i <= turnedOn && i < 4; i++) {
            for (int hr : hrs[i]) {
                if (turnedOn - i<7) {
                    for (int tmp : min[turnedOn - i]) {
                        if (tmp < 10) {
                            ans.push_back(to_string(hr) + ":0" +
                                          to_string(tmp));
                        } else {
                            ans.push_back(to_string(hr) + ":" + to_string(tmp));
                        }
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};