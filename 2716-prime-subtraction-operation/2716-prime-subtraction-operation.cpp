class Solution {
public:
    int prime(int x) {
        for (int i = x-1; i >= 1; i--) {
            int flag=0;
            for (int j = 2; j <= sqrt(i); j++) {
                if(i%j==0)flag=1;
            }
            if(flag ==0)return i;
        }
        return 1;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        
        nums[0]=(nums[0]<=2)?nums[0]:(nums[0]-prime(nums[0]));
        for(int i=1; i<n; i++){
            if(nums[i]-nums[i-1]<=0)return false;
            nums[i]=(nums[i]-nums[i-1]<=2)?nums[i]:(nums[i]-prime(nums[i]-nums[i-1]));
        }
        return true;
    }
};