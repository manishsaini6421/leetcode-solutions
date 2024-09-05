class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num=nums[0];
        int count=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==num){
                count++;
            }
            else if(nums[i]!=num && count==0){
                num=nums[i];
                count=1;
            }
            else
            count--;
        }
       
        return num;
    }
};