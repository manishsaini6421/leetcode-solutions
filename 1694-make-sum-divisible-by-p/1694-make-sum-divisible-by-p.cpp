class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
      
        long int sum=0;
        for(auto num:nums){
            sum=(sum+num)%p;
            
        }

        if(sum==0) return 0;
        int prefix_sum=0;
        map<int,int> map;
        map[0]=-1;
        int res=nums.size();
        for(int i=0; i<nums.size(); i++){
            prefix_sum =(prefix_sum+nums[i])%p;
            int temp = (prefix_sum - sum +p)%p;
           
                 if(map.find(temp)!=map.end()){
                res=min(res,i-map[temp]);
            
            }
           
            map[prefix_sum]=i;
        }
        if(res==nums.size()) return -1;
        return res;
    }
};