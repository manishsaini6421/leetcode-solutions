class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

        int n=meetings.size();
        for(auto meeting:meetings){
            cout<<meeting[0]<<" "<<meeting[1]<<endl;
        }
        int prev=meetings[0][1];
        int ans=0;
        ans+=max(0,meetings[0][0]-1);
        for(int i=1; i<n; i++){
            ans+=max(0,meetings[i][0]-prev-1);
            prev=meetings[i][1];
        }
        ans+=max(0,days-prev);
        return ans;
    }
};