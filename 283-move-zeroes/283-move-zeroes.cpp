class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0 || n==1){
            return;
        }
        int f=0,r=1;
        
        while(r<=n-1){
            if(nums[f]==0 && nums[r]!=0){
               int temp=nums[f];
                nums[f]=nums[r];
                nums[r]=temp;
            }
            else if(nums[f]==0 && nums[r]==0){
                r++;
            }
            else if(nums[f]!=0){
                f++;
                r++;
            }
        }
    }
};