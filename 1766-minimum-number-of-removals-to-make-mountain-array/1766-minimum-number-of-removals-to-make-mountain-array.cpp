class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
       int n=nums.size();
       
       vector<int> v1;
       vector<int> IncLen(n,0);
       for(int i=0; i<n; i++){
            auto it=lower_bound(v1.begin(),v1.end(),nums[i]);

            if(it==v1.end()) {
                v1.push_back(nums[i]);
                
            }
            else *it=nums[i];
            IncLen[i]=v1.size();
        }

        reverse(nums.begin(),nums.end());
        vector<int> v2;
        vector<int> DecLen(n,0);

        for(int i=0; i<n; i++){
            auto it=lower_bound(v2.begin(),v2.end(),nums[i]);

            if(it==v2.end())v2.push_back(nums[i]);
            else *it=nums[i];
            DecLen[i]=v2.size();
        }
        reverse(DecLen.begin(),DecLen.end());
        int ans=INT_MAX;
        for(int i=1; i<n-1; i++){
            if(IncLen[i]>1 && DecLen[i]>1)
                ans=min(ans,n+1-IncLen[i]-DecLen[i]);
        }
        return ans;
    }
};