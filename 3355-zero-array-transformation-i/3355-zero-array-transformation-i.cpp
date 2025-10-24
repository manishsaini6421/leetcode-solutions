class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int Q=queries.size();
        int n=nums.size();
        vector<int> diff(n+1,0);
        
        for(int i=0; i<Q; i++){
            diff[queries[i][0]]+=1;
            diff[queries[i][1]+1]-=1;
        }
        for(int i=1; i<n; i++){
            diff[i]+=diff[i-1];
        }
        bool result=true;
       
        for(int i=0; i<n; i++){
            if(nums[i]-diff[i]>0)return false;
        }
        return result;
    }
};