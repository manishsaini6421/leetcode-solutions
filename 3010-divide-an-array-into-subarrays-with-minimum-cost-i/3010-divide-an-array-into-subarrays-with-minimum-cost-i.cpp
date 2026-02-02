class Solution {
public:
    // int minimumCost(vector<int>& nums) {
    //     int ans=nums[0];
    //     int first=nums[1],second=INT_MAX,index=1;
    //     for(int i=1; i<nums.size(); i++){
    //         if(nums[i]<first){
    //             first=nums[i];
    //             index=i;
    //         }
    //     }
    //     for(int i=1; i<nums.size(); i++){
    //         if(nums[i]<second && i!=index){
    //             second=nums[i];
    //         }
    //     }
    //     return ans+first+second;
    // }


    int minimumCost(vector<int>& nums){
        priority_queue<int,vector<int> ,greater<>> pq(nums.begin()+1,nums.end());
        
        int ans=nums[0];
        ans+=pq.top();
        pq.pop();
        ans+=pq.top();
        return ans;
    }
};