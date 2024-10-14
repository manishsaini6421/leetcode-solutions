class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int> > pq;

        long long ans=0;
        for(auto num:nums){
            pq.push(num);
        }
        for(int i=0; i<k; i++){
            int temp=pq.top();
            ans+=temp;
            pq.pop();
            pq.push(ceil(temp/3.0));
        }
        return ans;
    }
};