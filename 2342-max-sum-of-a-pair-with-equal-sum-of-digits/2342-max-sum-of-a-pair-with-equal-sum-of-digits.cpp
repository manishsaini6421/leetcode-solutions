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
            int x=sumOfDigits(nums[i]);
            if(map[x].size()>1){
                if(map[x][0]<=nums[i] || map[x][1]<=nums[i]){
                    if(map[x][0]>map[x][1]){
                        map[x][1]=nums[i];
                    }
                    else{
                        map[x][0]=nums[i];
                    }
                }
            }
            else{
                map[x].push_back(nums[i]);
            }
            
        }
        int ans=-1;
        for(auto v:map){
            int size=v.second.size();
            if(size>1){
                ans=max(ans,v.second[0]+v.second[1]);
            }
        }
       
       
        return ans;
    }
};