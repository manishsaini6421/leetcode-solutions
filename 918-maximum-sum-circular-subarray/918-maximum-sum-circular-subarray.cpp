class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int n=nums.size();
        int sum1=0,sum2=0;
        int minSum=INT_MAX,maxSum=INT_MIN,totalSum=0;
       for(int i=0; i<n; i++){
           sum1+=nums[i];
           maxSum=max(maxSum,sum1);
           if(sum1<0){
               sum1=0;
           }
           sum2+=nums[i];
           minSum=min(minSum,sum2);
           if(sum2>0){
               sum2=0;
           }
           totalSum+=nums[i];
       }
        if(totalSum==minSum) return maxSum;
        return max(maxSum,totalSum-minSum);
       
    }
};