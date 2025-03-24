class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());

        int n=meetings.size();
        for(auto meeting:meetings){
            cout<<meeting[0]<<" "<<meeting[1]<<endl;
        }

        vector<vector<int>> v;
        v.push_back(meetings[0]);
        for(int i=1; i<n; i++){
           if(meetings[i][0]<=v.back()[1] && meetings[i][1]<=v.back()[1]) {
            continue;
           }
           else if(meetings[i][0]<=v.back()[1]){
                v.back()[1]=meetings[i][1];
            }
            else{
                v.push_back(meetings[i]);
            }
        }
        cout<<endl;
        for(auto val:v){
            cout<<val[0]<<" "<<val[1]<<endl;
        }
        int ans=0;
        int prev=1;
        for(auto val:v){
            ans+=val[0]-prev;
            prev=val[1]+1;
        }

        ans+=days-prev+1;
        return ans;
    }
};