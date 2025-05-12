class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        set<int> temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if(i==j || j==k || i==k){
                        continue;
                    }
                    if (digits[i] != 0) {
                        int num = digits[i]*100+digits[j]*10+digits[k];

                        if (num % 2 == 0) {
                            temp.insert(num);
                        }
                    }
                }
            }
        }
        for (auto num : temp) {
            ans.push_back(num);
        }
        return ans;
    }
};