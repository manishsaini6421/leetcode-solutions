class Solution {
public:
    int largestCombination(vector<int>& candidates) {
       int i=32,n=candidates.size(),ans=0;
        while(i>0){
            int count=0;
            for(int i=0; i<n; i++){
                if(candidates[i]&1)count++;
            }
            ans=max(ans,count);
            for(int i=0; i<n; i++){
                candidates[i]=candidates[i]>>1;
            }
            i--;
        }
        return ans;
    }
};