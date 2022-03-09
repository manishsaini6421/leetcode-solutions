class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                if(nums[i]>-1 && nums[i]>nums[i+1]){
                    return i;
                }
                
            }
            else if(i==n-1){
                if(nums[i]>nums[i-1] && nums[i]>INT_MIN){
                    return i;
                }
            }
            else{
                if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                    return i;
                }
            }
        }
        return 0;
    }
};