class Solution {
public:
int profit(vector<vector<int>>& events,int i,int cnt,vector<vector<int>>& memo,int n){
    if(cnt==2 || i>=events.size())return 0;
    
     if(memo[i][cnt]!=-1) return memo[i][cnt];
     int nextIndex=upper_bound(events,i,n);
     int take=events[i][2]+profit(events,nextIndex,cnt+1,memo,n);
     int donttake=profit(events,i+1,cnt,memo,n);
    
    return memo[i][cnt]=max(take,donttake);
}

int upper_bound(vector<vector<int>>& events, int index,int n){
    int l=index+1,h=n-1,nextIndex=n;
    while(l<=h){
        int mid=(l+h)/2;
        if(events[mid][0]>events[index][1]){
            nextIndex=mid;
            h=mid-1;
        }
        else l=mid+1;
    }
    return nextIndex;
}
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<vector<int>> memo(n,vector<int>(2,-1));
        return profit(events,0,0,memo,n);
    }
};