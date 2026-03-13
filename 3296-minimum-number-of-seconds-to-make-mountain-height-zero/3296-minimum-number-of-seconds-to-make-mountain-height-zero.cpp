class Solution {
public:
    long long findN(long long t,long long w){
        return (sqrt(1+(8*t)/w)-1)/2;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long start=0,end=1e16;

        long long t=LLONG_MAX,ans=0;
        
        while(start<=end){
            t=(start+end)/2;
            int h=mountainHeight;
            for(int w:workerTimes){
                int a=findN(t,w);
                h-=a;
                if(h<=0){
                    ans=t;
                    end=t-1;
                    break;
                }
            }
            if(h>0)start=t+1;
            
        }
        return ans;
    }
};