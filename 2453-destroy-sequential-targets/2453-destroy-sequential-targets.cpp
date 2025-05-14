class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(),nums.end());
       map<int,int> dp;
       for(auto num:nums){
        cout<<num<<" "<<num%space<<endl;
        dp[num%space]++;
       }
       int ans=0;
       int temp=0;
      for(auto num:nums){
       if(temp< dp[num%space]){
        temp=dp[num%space];
        ans=num;
       }
      }
        return ans;
        

    }
};