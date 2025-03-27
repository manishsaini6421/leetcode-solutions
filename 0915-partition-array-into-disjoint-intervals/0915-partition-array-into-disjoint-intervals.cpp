class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        vector<int> right(n,INT_MAX);
        right[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            right[i]=min(right[i+1],nums[i]);
        }
        int left=INT_MIN;
        for(int i=0; i<n-1; i++){
            left=max(left,nums[i]);
            if(left<=right[i+1])return i+1;
        }
        return n;
    }
};