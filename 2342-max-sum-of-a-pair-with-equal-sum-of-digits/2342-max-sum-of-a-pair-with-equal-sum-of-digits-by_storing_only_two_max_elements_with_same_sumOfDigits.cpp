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
        unordered_map<int,pair<int,int>> map;
        
        int n=nums.size();
        for(int i=0; i<n; i++){
            int x=sumOfDigits(nums[i]);
            if(map[x].first>0 && map[x].second>0){
                if(map[x].first<=nums[i] || map[x].second<=nums[i]){
                    if(map[x].first>map[x].second){
                        map[x].second=nums[i];
                    }
                    else{
                        map[x].first=nums[i];
                    }
                }
            }
            else{
                if(map[x].first>0){
                    map[x].second=nums[i];
                }
                else{
                    map[x].first=nums[i];
                }
            }
            
        }
        int ans=-1;
        for(auto v:map){
            int x=v.second.first;
            int y=v.second.second;
            if(x>0 && y>0){
                ans=max(ans,x+y);
            }
        }
       
       
        return ans;
    }
};