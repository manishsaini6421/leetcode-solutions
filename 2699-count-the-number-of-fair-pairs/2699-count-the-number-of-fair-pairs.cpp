class Solution {
public:

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
       long long count1=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j){
            if(nums[i]+nums[j]<=upper){
                count1+=(j-i);
                i++;
            }
            else{
                j--;
            }
        }
        i=0,j=n-1;
        long long count2=0;
        while(i<j){
            if(nums[i]+nums[j]<lower){
                count2+=(j-i);
                i++;
            }
            else{
                j--;
            }
        }
        return count1-count2;;
    }
};