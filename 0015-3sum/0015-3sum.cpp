class Solution {
public:
//sort and Use binary search for third element
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        set<vector<int>> temp;
        for(int i=0; i<n-2; i++){
            int j=i+1,k=n-1;
           while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    temp.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }else k--;
           }
        }
        vector<vector<int>> ans;
        for(auto v:temp){
            ans.push_back(v);
        }
        return ans;
    }
};