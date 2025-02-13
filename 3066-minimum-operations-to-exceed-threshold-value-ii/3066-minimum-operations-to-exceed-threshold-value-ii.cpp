class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long,vector<long> ,greater<long>> pq(nums.begin(),nums.end());
       
        int ans=0;
       
        while(pq.top()<k && pq.size()>1){
            long x=pq.top();
            pq.pop();
            long y=pq.top();
            pq.pop();
            pq.push(min(x,y)*2+max(x,y));
            ans++;
        }
        return ans;

    }
};