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
            map[sumOfDigits(nums[i])].push_back(i);
        }
        int ans=-1;
        for(auto v:map){
            for(int i=0; i<v.second.size(); i++){
                for(int j=i+1; j<v.second.size(); j++){
                    ans=max(ans,nums[v.second[i]]+nums[v.second[j]]);
                }
            }
        }
       
       
        return ans;
    }
};