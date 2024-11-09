class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool> v;
        int x=0;
       for(int i=0; i<n; i++){
        x=(2*x+nums[i])%5;
        v.push_back(x==0);
       }
        return v;
    }
};