class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n=nums.size();
        vector<int> freq(100001,0);
        vector<int> freqSum(100001,0);
        for(auto num:nums){
            freq[num]++;
        }
        freqSum[0]=freq[0];
        for(int i=1; i<100001; i++){
            freqSum[i]=freq[i]+freqSum[i-1];
        }
        int ans=1;
        for(int target=0; target<100001; target++){
            if(target-k-1 >=0 && target+k<=100000)
             ans=max(ans,freq[target]+min(freqSum[target+k]-freqSum[target-k-1]-freq[target],numOperations));
        }
        return ans;
    }
};