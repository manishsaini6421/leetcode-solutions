class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=i  && nums[i]<nums.size()){
                int x=nums[i];
                int y=nums[x];
                nums[x]=x;
                nums[i]=y;
                if(x==y)
                i++;

            }
            else
            i++;
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=i)
            return i;
        }
        return nums.size();
    }
};