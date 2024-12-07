class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        while(left<=right){
            int mid=(left+right)/2;
            long long eat=0;
            for(auto pile:piles){
                eat += (pile + mid - 1) / mid;
            }
            if(eat<=h)right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};