class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res=0;
        vector<int> freq(60,0);
        for(auto num:time){
            freq[num%60]++;
        }

        long long a=freq[0];
        res+=(a*(a-1))/2;
        long long b=freq[30];
        res+=(b*(b-1))/2;

        for(int i=1; i<30; i++){
            res+=freq[i]*freq[60-i];
        }
        return res;
    }
};