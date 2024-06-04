class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=i+1){
                int x=nums[i];
                int y=nums[x-1];
                nums[x-1]=x;
                nums[i]=y;
                if(x==y)
                return x;
            }
            else
            i++;
            
        }
        return nums[nums.size()];
    }
};