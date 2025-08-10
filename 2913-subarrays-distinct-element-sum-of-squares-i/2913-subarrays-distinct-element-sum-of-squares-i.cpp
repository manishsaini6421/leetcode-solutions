class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            map<int,int> count;
            for(int j=i; j<n; j++){
                count[nums[j]]++;
                int t=count.size();
                ans+=(t*t);

            }
        }
        
        return ans;
    }
};