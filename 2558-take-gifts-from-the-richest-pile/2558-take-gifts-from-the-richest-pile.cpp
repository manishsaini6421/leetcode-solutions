class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(),gifts.end());

        for(int i=0; i<k; i++){
            int temp=maxHeap.top();
            maxHeap.pop();
            
            maxHeap.push(sqrt(temp));
        }
        long long ans=0;
        int n=gifts.size();
        for(int i=0; i<n; i++){
            ans+=maxHeap.top();
            maxHeap.pop();
        }
        return ans;
    }
};