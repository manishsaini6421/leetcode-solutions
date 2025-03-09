class Solution {
public:
    
    int solveTab(vector<int>& nums, int n, int target) {
        vector<int> prev(target+1,false);
        vector<int> curr(target+1);
       
        for(int j=0; j<=target; j++){
            prev[j]=(nums[0]==j)?true:false;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<=target; j++){
                bool take=false;
                if(j-nums[i]>=0)take=prev[j-nums[i]];
                bool dontTake=prev[j];
                curr[j]=(take || dontTake);
            }
            prev=curr;
        }
       
        return prev[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        
        if (sum % 2)
            return false;
        return solveTab(nums, n , sum / 2);
    }
};