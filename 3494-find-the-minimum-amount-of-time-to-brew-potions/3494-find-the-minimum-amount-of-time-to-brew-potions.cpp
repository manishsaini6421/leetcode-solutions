
class Solution {
public:
    
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<long long> time(n);
       

        for(int j=0; j<m; j++){
            long long curr_time=0;
            for(int i=0; i<n; i++){
                curr_time=max(curr_time,time[i])+skill[i]*mana[j];
            }
            time[n-1]=curr_time;
            for(int i=n-2; i>=0; i--){
                time[i]=time[i+1]-skill[i+1]*mana[j];
            }
        }
        return time[n-1];
    }
};