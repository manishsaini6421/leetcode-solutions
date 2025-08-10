class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap(piles.begin(),piles.end());

        for(int i=0; i<k; i++){
            int temp=maxHeap.top();
            maxHeap.pop();
            temp-=temp/2;
            maxHeap.push(temp);
        }
        int ans=0;
        while(!maxHeap.empty()){
            ans+=maxHeap.top();
            maxHeap.pop();
        }
        return ans;
        
    }
};