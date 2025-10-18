class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        map<int,int> mp;
        
        for(int i=0; i<n; i++){
            int temp=-k;
            while(mp.count(nums[i]+temp) && temp<k){
                temp++;
            }
            mp[nums[i]+temp]=1;
        }

        return mp.size();
    }
};