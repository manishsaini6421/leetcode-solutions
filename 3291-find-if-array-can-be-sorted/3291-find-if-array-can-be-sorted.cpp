class Solution {
public:
    int setBits(int num){
        int count=0;
        while(num){
            count+=num&1;
            num>>=1;
        }
        return count;
    }
    bool canSortArray(vector<int>& nums) {
        int maxPrevSegment=0,maxCurrSegment=nums[0],count=setBits(nums[0]);

        for(int i=1; i<nums.size(); i++){
            if(setBits(nums[i])==count && nums[i]>maxPrevSegment){
                maxCurrSegment=max(maxCurrSegment,nums[i]);
            }
            else if(maxPrevSegment<nums[i] && maxCurrSegment<nums[i]){
               maxPrevSegment=maxCurrSegment;
                maxCurrSegment=nums[i];
                count=setBits(nums[i]);
            }
            else return false;
        }
        return true;
    }
};