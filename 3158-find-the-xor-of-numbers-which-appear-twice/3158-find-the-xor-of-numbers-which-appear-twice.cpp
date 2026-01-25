class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        for(auto m:mp){
            if(m.second==2)ans^=m.first;

        }
        return ans;
    }
};