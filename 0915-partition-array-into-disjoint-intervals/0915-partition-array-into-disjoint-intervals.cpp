class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int leftMax=nums[0];
        int globalMax=nums[0];
        for(int i=0; i<n; i++){
            if(nums[i]<leftMax){
                ans=i;
                leftMax=globalMax;
            }
            else{
                globalMax=max(globalMax,nums[i]);
                
            }
            
        }
        return ans+1;
    }
};