class Solution {
public:
//sort and Use binary search for third element
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        for(int i=0; i<n-2; i++){
            //Skip first duplicate element
            if(i>0 && nums[i]==nums[i-1])continue;
            if(nums[i]>0)break;

            int j=i+1,k=n-1,x=INT_MAX,y=INT_MAX;
           while(j<k){

                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    x=nums[j];
                    y=nums[k];
                    j++;
                    k--;
                    //Skip second duplicate element
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    //Skip third duplicate element
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
                else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }else k--;
           }
        }
        
        return ans;
    }
};