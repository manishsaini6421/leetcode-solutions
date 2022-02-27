class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
     
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int i=n-1;
        while(i>=2){
            if(nums[i-1]+nums[i-2]>nums[i]){
                return nums[i-2]+nums[i-1]+nums[i];
            }
            i--;
        }
        return 0;
    }
};