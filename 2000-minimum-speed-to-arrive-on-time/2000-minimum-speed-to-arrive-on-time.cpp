class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left=1;
        int right =1000000000;
        int n=dist.size();
        if(hour<=n-1)return -1;
        while(left<=right){
            int mid=(left+right)/2;
            int time=0;
            for(int i=0; i<n-1; i++){
                time+=(dist[i]+mid-1)/mid;
            }
            double x=(double)dist[n-1]/mid;
            if(x+time<=hour)right=mid-1;
            else left=mid+1;

        }
        return left;
    }
};