class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n,0);
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                result[i]=nums[(i+nums[i])%n];
            }
            else if(nums[i]<0){
                int index=((i+nums[i])%n)>=0?((i+nums[i])%n): n- abs((i+nums[i])%n);
                result[i]=nums[index];
            }
            else result[i]=nums[i];
        }
        return result;
    }
};