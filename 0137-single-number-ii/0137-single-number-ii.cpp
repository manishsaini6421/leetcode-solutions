class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=1,x=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]!=x){
                if(count==1)
                    return x;
                x=nums[i];
                count=1;    
            }
            else count++;
        }
        return nums[n-1];

    }
};