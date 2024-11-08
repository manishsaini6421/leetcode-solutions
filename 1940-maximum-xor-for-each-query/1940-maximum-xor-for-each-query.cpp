class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x=nums[0];
        int n=nums.size();
        for(int i=1; i<n; i++){
            x^=nums[i];
        }
        vector<int> v;
        int mask=(1<<maximumBit)-1;
        
        for(int i=n-1; i>=0; i--){
            v.push_back(x^mask);
            x^=nums[i];
        }
        return v;
    }
};