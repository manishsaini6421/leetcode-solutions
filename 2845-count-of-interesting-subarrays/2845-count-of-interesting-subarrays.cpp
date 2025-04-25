class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans=0;
        int n=nums.size();
        
        int prefix=0;

        unordered_map<int,int> map;
        map[0]=1;
        for(int i=0; i<n; i++){
            prefix+=(nums[i]%modulo==k);
            prefix%=modulo;
            ans+=map[(prefix-k+modulo)%modulo];
            map[prefix]++;
        }
        
        return ans;
    }
};