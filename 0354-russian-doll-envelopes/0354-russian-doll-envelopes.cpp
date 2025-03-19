class Solution {
public:
    static bool manual(vector<int>v1, vector<int>v2){
        if(v1[0]<v2[0])return true;
        else if(v1[0]==v2[0]) return v1[1]>v2[1];
        return false;
    }
    int solve(vector<vector<int>>& envelopes){
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        int n=envelopes.size();
        for(int i=1; i<n; i++){
            if(ans.back()<envelopes[i][1]){
                ans.push_back(envelopes[i][1]);
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[index]=envelopes[i][1];

            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),manual);
        int n=envelopes.size();

        return solve(envelopes);
    }
};