class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> m;
        int n=nums.size();
        int sum=0,ans=0;
        int start=0,end=0;
        while(start<n && end<n){
            if(m[nums[end]]==0){
                m[nums[end]]++;
                sum+=nums[end];
                ans=max(sum,ans);
                end++;
            }
            else{
                m[nums[start]]=0;
                sum-=nums[start];
                start++;
            }
        }
        return ans;
    }
};