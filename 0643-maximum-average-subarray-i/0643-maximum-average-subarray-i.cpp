class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0;
        for(int i=0; i<k; i++){
            sum+=nums[i];
        }
        double ans=INT_MIN;
        for(int i=k; i<n; i++){
          
            ans=max(ans,sum/k);
            cout<<ans<<endl;
            sum-=nums[i-k];
            sum+=nums[i];
        }
        ans=max(ans,sum/k);
        return ans;
    }
};