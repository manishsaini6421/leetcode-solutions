class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> ones(n,0);
        
        ones[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            ones[i]=ones[i+1]+nums[i];
        }
        int zeros=0;
        int maxCount=0;
        unordered_map<int,int> map;
        for(int i=0; i<n; i++){
            map[i]=zeros+ones[i];
            if(maxCount<map[i])maxCount=map[i];
            if(nums[i]==0)zeros++;
        }
        map[n]=zeros;
        if(maxCount<map[n])maxCount=map[n];
        vector<int> ans;
        for(auto pair:map){
            if(pair.second==maxCount)ans.push_back(pair.first);
        }
        return ans;
    }
};