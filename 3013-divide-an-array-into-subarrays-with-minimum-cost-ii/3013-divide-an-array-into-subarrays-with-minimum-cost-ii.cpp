class Solution {
public:
    
    long long minimumCost(vector<int>& nums, int k, int dist) {
        //Use dp by choosing i take or dont take as starting of any subarray
        multiset<int> low,high;
        int n=nums.size();
        long long currSum=0;

        for(int i=1; i<=dist+1; i++){
            low.insert(nums[i]);
            currSum+=nums[i];
            if(low.size()>k-1){
                auto it=prev(low.end());
                high.insert(*it);
                currSum-=*it;
                low.erase(it);
            }
        }
        long long ans=nums[0]+currSum;
        for(int i=dist+2; i<n; i++){
           int out=nums[i-dist-1];
           if(!low.empty() && low.find(out)!=low.end()){
            currSum-=out;
            low.erase(low.find(out));
           }
           else{
            high.erase(high.find(out));
           }

           if((!low.empty() && *prev(low.end())>nums[i]) || low.empty()){
            low.insert(nums[i]);
            currSum+=nums[i];
            if(low.size()>k-1){
                auto it=prev(low.end());
                currSum-=*it;
                high.insert(*it);
                low.erase(it);
            }
           }
           else{
            high.insert(nums[i]);
           }
           if(low.size()<k-1 && !high.empty()){
            auto it=high.begin();
                low.insert(*it);
                currSum+=*it;
                high.erase(it);
            }
            ans=min(ans,nums[0]+currSum);
        }
        return ans;

    }
};