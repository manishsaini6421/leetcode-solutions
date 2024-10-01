class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<int> freq(24,0);
        long long res=0;
        for(auto num:hours){
            freq[num%24]++;
        }
        
        long long a=freq[0];
        res+=(a*(a-1))/2;
        long long b=freq[12];
        res+=(b*(b-1))/2;

        for(int i=1; i<12; i++){
            res+=freq[i]*freq[24-i];
        }
        return res;
    }
};