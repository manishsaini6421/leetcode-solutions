class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long i=0,j=j = (long long) cars * cars * (*min_element(ranks.begin(), ranks.end()));
        long long ans=0;
        int n=ranks.size();
        while(i<=j){
            long long mid=(i+j)/2;

            long long count=0;
            for(int k=0; k<n; k++){
                count+=sqrt(mid/ranks[k]);
                
            }
            if(count>=cars){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};