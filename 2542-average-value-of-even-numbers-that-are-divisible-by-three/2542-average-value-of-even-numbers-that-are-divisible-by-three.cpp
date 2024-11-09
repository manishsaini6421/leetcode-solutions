class Solution {
public:
    int averageValue(vector<int>& nums) {
        int count=0;
        int sum=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]%6==0){
                count++;
                sum+=nums[i];
            }
        }
        
        return (count)?sum/count:0;
    }
};