class Solution {
public:

    int minimumSize(vector<int>& nums, int maxOperations) {
       int left=1;
       int right =0;
       int n=nums.size();
        for(int i=0; i<n; i++){
            right=max(right,nums[i]);
        }
        
        int x=0;
        while(left<right){
            int operations=0;
            int mid=(left+right)/2;
            for(int i=0; i<n; i++){
                if(nums[i]>mid){
                    operations+=(nums[i]-1)/mid;
                } 
            }
            if(operations>maxOperations)left=mid+1;
            else right=mid;

        }
        
        return left;
    }
};