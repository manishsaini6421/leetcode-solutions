class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int> s;
        for(auto num:nums){
            s.insert(num);
        }
        int ans=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int count=0;
          int temp=nums[i];
            for(int j=1; j<=5; j++){
                if(s.find(temp)!=s.end())count++;
                else break;
                if(temp>10000)break;
                temp*=temp;
            }
            if(count>ans)
                ans=count;
        }
        if(ans==1)return -1;
        return ans;
    }
};