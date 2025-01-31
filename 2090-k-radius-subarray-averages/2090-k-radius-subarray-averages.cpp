class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,-1);
        if(2*k+1>n){
            return ans;
        }
        long int sum=0;
        for(int i=0; i<2*k+1; i++){
            sum+=nums[i];
        }
        int j=0;
        for(int i=k; i+k+1<n; i++){
            cout<<sum<<endl;
            ans[i]=sum/(2*k+1);
            sum-=nums[i-k];
            sum+=nums[i+k+1];
            j=i;
        }
        cout<<j<<endl;
        ans[n-k-1]=sum/(2*k+1);
        return ans;
    }
};