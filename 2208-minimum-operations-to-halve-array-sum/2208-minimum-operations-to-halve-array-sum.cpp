class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> maxHeap(nums.begin(),nums.end());
        double sum=accumulate(nums.begin(),nums.end(),0.0);
        double initialHalfSum=sum/2;
        int ans=0;
        while(sum>initialHalfSum){
            double x=maxHeap.top();
            maxHeap.pop();
            sum-=x/2;
            maxHeap.push(x/2);
            ans++;
        }
        return ans;
    }
};