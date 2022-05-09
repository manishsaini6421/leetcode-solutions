class Solution {
public:
    int getMaximumGenerated(int n) {
       if(n<2) return n;
        
        int nums[n+1];
        nums[0]=0,nums[1]=1;
        int m=0;
        for(int i=2; i<=n; i++){
            if(i%2) nums[i] = nums[i/2] + nums[i/2 + 1];
            else nums[i] = nums[i/2];
            
            m= max(nums[i],m);
        }
        return m;
    }
};