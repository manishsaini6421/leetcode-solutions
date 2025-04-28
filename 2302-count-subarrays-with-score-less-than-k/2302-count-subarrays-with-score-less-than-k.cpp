class Solution {
public:

    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        vector<long long> prefixSum;
        prefixSum.push_back(0);
        for(int i=0; i<n; i++){
            prefixSum.push_back(prefixSum.back()+nums[i]);
        }
        long long ans=0;
        for(int i=1; i<=n; i++){
            int j=0,l=i,index=i;
            while(j<=l){
                int mid=(j+l)/2;
                if(mid>0 && (prefixSum[i]-prefixSum[mid-1])*(i-mid+1)<k){
                    index=mid;
                    l=mid-1;
                }
                else{
                    j=mid+1;
                }
            }
            if(i-index==0){
                if(nums[i-1]<k) ans++;
                
            }
            else{
                ans+=(i-index+1);
            }
        }
        return ans;
    }
};