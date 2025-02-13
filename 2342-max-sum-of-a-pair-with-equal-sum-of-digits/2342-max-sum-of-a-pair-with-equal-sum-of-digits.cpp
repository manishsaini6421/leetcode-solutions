class Solution {
public:
    int sumOfDigits(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
  
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> map;
        int n=nums.size();
        for(int i=0; i<n; i++){
            map[sumOfDigits(nums[i])].push_back(nums[i]);
        }
        int ans=-1;
        for(auto v:map){
            int size=v.second.size();
            if(size>1){
                sort(v.second.begin(),v.second.end());
                ans=max(ans,v.second[size-1]+v.second[size-2]);
            }
        }
       
       
        return ans;
    }
};