class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid,f=0,r=nums.size()-1;
        while(r>=f){
            mid=(f+r)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target>nums[mid]){
                f=mid+1;
            }
            else if(target<nums[mid]){
                r=mid-1;
            }
            else if(target<nums[0]){
                return 0;
            }
            else if(target>nums[r]){
                return r+1;
            }
        }
        return f;
    }
};