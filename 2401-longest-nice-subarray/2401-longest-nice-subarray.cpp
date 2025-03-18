class Solution {
public:
    
    int longestNiceSubarray(vector<int>& nums) {
        int ans=1;
        int temp=nums[0],count=1;
        int prev=0;
        int n=nums.size();
        for(int i=1; i<n; i++){
            if(!(temp&nums[i])){
                count++;
                temp|=nums[i];

            }
            else{
                
                temp^=nums[prev];
                count--;
                i--;
                prev++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};