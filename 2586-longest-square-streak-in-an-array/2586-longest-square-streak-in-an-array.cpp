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
            vector<int> v;
          int temp=nums[i];
            for(int j=1; j<=5; j++){
                if(s.find(temp)!=s.end())v.push_back(temp);
                else break;
                if(temp>10000)break;
                temp*=temp;
            }
            cout<<v.size()<<""<<ans<<endl;

            if(v.size()>ans)
                ans=v.size();
        }
        if(ans==1)return -1;
        return ans;
    }
};