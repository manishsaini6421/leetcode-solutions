class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v;
        int j=k%n;
       
        for(int i=n-j; i<n; i++){
            v.push_back(nums[i]);
        }
        for(int i=0; i<n-j; i++){
            v.push_back(nums[i]);
        }
        nums=v;
    }
};