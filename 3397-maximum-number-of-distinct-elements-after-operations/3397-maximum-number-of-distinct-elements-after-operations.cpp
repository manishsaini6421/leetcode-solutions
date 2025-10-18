class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        map<int,int> mp;
        
        for(int i=0; i<n; i++){
            
            int a=-k;
            int b=k;
            int temp,ans=0;
            while(a<=b){
                temp=(a+b)/2;
                if(!mp.count(nums[i]+temp)){
                    ans=temp;
                    b=temp-1;
                }
                else a=temp+1;
            }
            mp[nums[i]+ans]=1;
        }

        return mp.size();
    }
};