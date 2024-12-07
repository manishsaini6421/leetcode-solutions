class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left=1;
        long long right=1e14;
        long long result=-1;
        while(left<=right){
            long long mid=(left+right)/2;
            long long trips=0;
            for(auto timei:time){
                trips+=(mid/timei);
            }
            if(trips>=totalTrips){
                result=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return result;
    }
};