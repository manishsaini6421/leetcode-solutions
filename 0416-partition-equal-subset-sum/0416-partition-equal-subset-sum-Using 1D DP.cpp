class Solution {
public:
    
    int solveTabOpt(vector<int>& nums, int n, int target) {
        vector<int> curr(target+1);
       
        for(int j=0; j<=target; j++){
            curr[j]=(nums[0]==j)?true:false;
        }
        for(int i=1; i<n; i++){
            for(int j=target; j>=1; j--){
                bool take=false;
                if(j-nums[i]>=0)take=curr[j-nums[i]];
                bool dontTake=curr[j];
                curr[j]=(take || dontTake);
            }
        }
       
        return curr[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        
        if (sum % 2)
            return false;
        return solveTabOpt(nums, n , sum / 2);
    }
};