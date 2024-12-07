class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left=1;
        int right=*max_element(candies.begin(),candies.end());
       
        while(left<=right){
            long long given=0;
            int mid=(left+right)/2;
            for(auto pile:candies){
                given+=pile/mid;
            }
            if(given>=k)left=mid+1;
            else right=mid-1;


        }
        return left-1;
    }
};