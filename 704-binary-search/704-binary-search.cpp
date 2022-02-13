class Solution {
public:
    int search(vector<int>& nums, int target) {
       int size=nums.size()-1;
        int f=0,r=size,temp;
        while(r>=f ){
            temp=(r+f)/2;
               if(target==nums[temp]){
                return temp;
            }
           else if(target>nums[temp]){
                f=temp+1;
                
            }
            else {
                r=temp-1;
            }
         
        }
        return -1;
    }
};