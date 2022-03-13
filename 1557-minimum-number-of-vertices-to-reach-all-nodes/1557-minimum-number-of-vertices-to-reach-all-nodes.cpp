class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> m;
      
        vector<int> in(n+1,0);
        for(auto x:edges){
            in[x[1]]++;
        }
        vector<int> v;
        for(int i=0; i<n; i++){
            if(in[i]==0)
                v.push_back(i);
        }
        return v;
    }
};