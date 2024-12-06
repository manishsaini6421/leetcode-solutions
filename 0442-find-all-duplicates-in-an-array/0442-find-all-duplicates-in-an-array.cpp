class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        for(int i=0; i<n; i++){
            nums[abs(nums[i])-1]=-1*nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1]>0)result.push_back(abs(nums[i]));
          
        }
        
        return result;
    }
};