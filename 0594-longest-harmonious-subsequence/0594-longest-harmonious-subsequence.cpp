class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> freq;
        int n=nums.size();
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        int ans=0;

        int key=freq.begin()->first;
        int value=freq.begin()->second;
        for(auto pair:freq){
            if(pair.first-key==1 && pair.second+value>ans){
                ans=pair.second+value;
            }
            key=pair.first;
            value=pair.second;
        }
        return ans;
    }
};