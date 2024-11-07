class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        int n= candidates.size();
        int maxVal=INT_MIN;
        for(auto num:candidates){
            maxVal=max(num,maxVal);
        }
        for(int i=0; i<=logb(maxVal); i++){
            int temp=0;
            for(int j=0; j<n; j++){
                temp+=candidates[j]&1;
                candidates[j]>>=1;
            }
            ans=max(temp,ans);
        }
        return ans;
    }
};