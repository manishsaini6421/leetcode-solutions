class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMin=0,currMax=0,maxSum=0,minSum=0;
        for(auto num:nums){
            currMin=min(num,num+currMin);
            currMax=max(num,num+currMax);
            maxSum=max(maxSum,currMax);
            minSum=min(minSum,currMin);

        }        
        return max(abs(maxSum),abs(minSum));

    }
};