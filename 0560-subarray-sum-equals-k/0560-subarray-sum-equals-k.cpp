class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> map;
        map[0]=1;
        
        int ans=0;
        int total=0;
        for(int i=0; i<n; i++){
            total+=nums[i];
            map[total]++;
            
            ans+=map[total-k];
             cout<<total-k<<" "<<total<<" "<<ans<<endl;
        }
        if(k==0)ans=ans-n;
        return ans;
    }
};