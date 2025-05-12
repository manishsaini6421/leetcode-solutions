class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        set<int> temp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (digits[i] != 0) {
                        int num =
                            stoi(to_string(digits[i]) + to_string(digits[j]) +
                                 to_string(digits[k]));
                        
                        if (num % 2 == 0) {
                            temp.insert(num);
                        }
                        num =
                            stoi(to_string(digits[i]) + to_string(digits[k]) +
                                 to_string(digits[j]));
                        
                        if (num % 2 == 0) {
                            temp.insert(num);
                        }
                    }
                    if (digits[j] != 0) {
                        int num =
                            stoi(to_string(digits[j]) + to_string(digits[i]) +
                                 to_string(digits[k]));
                        
                        if (num % 2 == 0) {
                            temp.insert(num);
                        }
                        num =
                            stoi(to_string(digits[j]) + to_string(digits[k]) +
                                 to_string(digits[i]));
                        
                        if (num % 2 == 0) {
                            temp.insert(num);
                        }
                    }
                    if (digits[k] != 0) {
                        int num =
                            stoi(to_string(digits[k]) + to_string(digits[j]) +
                                 to_string(digits[i]));
                        
                        if (num % 2 == 0) {
                            temp.insert(num);
                        }
                        num =
                            stoi(to_string(digits[k]) + to_string(digits[i]) +
                                 to_string(digits[j]));
                        
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