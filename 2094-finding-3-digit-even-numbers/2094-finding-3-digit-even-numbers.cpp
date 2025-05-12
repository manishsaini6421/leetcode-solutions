class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        unordered_map<int,int> map;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if(i==j || j==k || i==k){
                        continue;
                    }
                    if (digits[i] != 0) {
                        int num = digits[i]*100+digits[j]*10+digits[k];

                        if (num % 2 == 0) {
                            map[num]++;
                        }
                    }
                }
            }
        }
        for (auto num : map) {
            ans.push_back(num.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};