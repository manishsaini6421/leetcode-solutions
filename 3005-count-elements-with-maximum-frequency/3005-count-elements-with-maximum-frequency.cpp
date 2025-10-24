class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto num:nums){
            freq[num]++;
        }
        int maxFreq=0;
        for(auto pair:freq){
            if(pair.second>maxFreq)maxFreq=pair.second;
        }
        int ans=0;
        for(auto pair:freq){
            if(pair.second==maxFreq)ans+=pair.second;
        }
        return ans;
    }
};