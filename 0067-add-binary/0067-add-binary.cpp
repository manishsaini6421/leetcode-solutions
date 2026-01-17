class Solution {
public:
    string addBinary(string a, string b) {
        int indexA = a.size() - 1, indexB = b.size() - 1;
        int c = 0;
        string ans = "";
        while (indexA >= 0 && indexB >= 0) {
            int x = (a[indexA] - '0') + (b[indexB] - '0') + c;
            if (x == 0 || x == 1) {
                ans = to_string(x) + ans;
                c=0;
            } else if (x == 2) {
                ans = '0' + ans;
                c = 1;
            } else {
                ans = '1' + ans;
                c = 1;
            }
            indexA--;
            indexB--;
        }
        while (indexA >= 0) {
            int x = (a[indexA] - '0') + c;
            if (x == 0 || x == 1) {
                ans = to_string(x) + ans;
                c=0;
            } else if (x == 2) {
                ans = '0' + ans;
                c = 1;
            } else {
                ans = '1' + ans;
                c = 1;
            }
            indexA--;
        }
        while (indexB >= 0) {
            int x = (b[indexB] - '0') + c;
            if (x == 0 || x == 1) {
                ans = to_string(x) + ans;
                c=0;
            } else if (x == 2) {
                ans = '0' + ans;
                c = 1;
            } else {
                ans = '1' + ans;
                c = 1;
            }
            indexB--;
        }
        if(c>0){
            ans='1'+ans;
        }
        return ans;
    }
};