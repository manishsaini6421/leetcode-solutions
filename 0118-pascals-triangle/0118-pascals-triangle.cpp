class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>  ans;
        vector<int> v;
        v.push_back(1);
        ans.push_back(v);
        for(int i=0; i<numRows-1; i++){
            vector<int> v1;
            v1.push_back(1);
            for(int j=0; j<ans[i].size()-1; j++){
                v1.push_back(ans[i][j]+ans[i][j+1]);
            }
            v1.push_back(1);
            ans.push_back(v1);
        }
        return ans;
    }
};