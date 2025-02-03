class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        set<int> s;
        int n=points.size();
        for(int i=0; i<n; i++){
            s.insert(points[i][0]);
        }
        int ans=0,start=*s.begin();
        for(auto x:s){
            if(x-start<=w)continue;
            ans++;
            start=x;
        }
        ans++;
        return ans;
    }
};