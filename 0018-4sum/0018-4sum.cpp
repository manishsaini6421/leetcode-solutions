class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<n-3; i++){
            //Skip first duplicate element
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int k=j+1,l=n-1;
                while(k<l){
                    long long sum=0ll+nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        //Skip third duplicate element
                        while(k<l && nums[k]==nums[k-1])k++;
                        //Skip forth duplcate element
                        while(k<l && nums[l]==nums[l+1])l--;
                    }
                    else if(sum<target)k++;
                    else l--;
                }

            }
        }
        return ans;
    }
};