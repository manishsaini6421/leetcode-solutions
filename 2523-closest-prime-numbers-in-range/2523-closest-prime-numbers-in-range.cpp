class Solution {
public:
    bool isPrime(int n) {
        if (n == 1)
            return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {

        vector<int> ans(2, -1);
        int prev2 = -1, prev1 = -1, diff = INT_MAX;
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                if (prev2 == -1) {
                    prev2 = i;
                } else if (prev1 == -1) {
                    prev1 = i;
                    diff = prev1 - prev2;
                    ans[0] = prev2;
                    ans[1] = prev1;
                } else {
                    prev2 = prev1;
                    prev1 = i;
                    if (prev1 - prev2 < diff) {
                        diff = prev1 - prev2;
                        ans[0] = prev2;
                        ans[1] = prev1;
                    }
                }
            }
        }
        if (prev1 == -1 || prev2 == -1)
            return {-1, -1};

        return ans;
    }
};