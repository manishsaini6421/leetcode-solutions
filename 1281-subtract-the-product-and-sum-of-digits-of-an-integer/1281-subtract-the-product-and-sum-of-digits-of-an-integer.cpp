class Solution {
public:
    int subtractProductAndSum(int n) {
        string s=to_string(n);
        int pro=1;
        int sum=0;
        for(int i=0; i<s.size(); i++){
            pro*=s[i]-'0';
            sum+=s[i]-'0';
        }
        return pro-sum;
    }
};