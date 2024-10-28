class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto num:nums){
            map[num]=1;
        }
        int ans=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int count=0;
            int temp=nums[i];
            for(int j=1; j<=5; j++){
                if(map[temp]==1)count++;
                else break;
                if(temp>350)break;
                temp*=temp;
            }
            if(count>ans)
                ans=count;
        }
        if(ans==1)return -1;
        return ans;
    }
};