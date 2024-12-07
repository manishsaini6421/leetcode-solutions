class Solution {
public:

    int minimumSize(vector<int>& nums, int maxOperations) {
       int left=1;
       int right =*max_element(nums.begin(),nums.end());
        
        while(left<right){
            int operations=0;
            int mid=(left+right)/2;
            for(auto num:nums){
                    operations+=(num-1)/mid;
                
            }
            if(operations>maxOperations)left=mid+1;
            else right=mid;

        }
        
        return left;
    }
};