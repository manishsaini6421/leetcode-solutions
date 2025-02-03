class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        set<int> s;
        for(auto point:points){
            s.insert(point[0]);
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