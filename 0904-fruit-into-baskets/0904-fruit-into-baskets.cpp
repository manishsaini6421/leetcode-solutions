class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n <= 2)
            return n;

        int arr[2];

        int ans = 0, x = 0, y = 0, index = 0;
        arr[0] = fruits[0];
        arr[1] = -1;
        for (int i = 0; i < n; i++) {

            if (fruits[i] == arr[0]) {
                if(y>x)
                x = i;
            } else if (fruits[i] == arr[1]) {
                if (x>y) {
                    y = i;
                }

            } else {
                arr[0] = fruits[i - 1];
                arr[1] = fruits[i];
                index = max(x,y);
                y = i;
                x=i-1;
            }
            ans = max(ans, i - index + 1);

            cout << ans << endl;
        }
        return ans;
    }
};