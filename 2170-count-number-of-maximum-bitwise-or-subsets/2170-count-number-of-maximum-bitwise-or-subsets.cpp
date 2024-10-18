class Solution {
public:
    
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR=0,ans=0;
        int n=nums.size(),subsetSize=pow(2,n);
        for(auto num:nums){
            maxOR|=num;
        }
        for(int i=0; i<subsetSize; i++){
            int temp=0;
            for(int j=0; j<n; j++){
                if(i & (1<<j)) temp|=nums[j];
            }
           
            if(temp==maxOR)ans++;
        }
        return ans;
    }
};