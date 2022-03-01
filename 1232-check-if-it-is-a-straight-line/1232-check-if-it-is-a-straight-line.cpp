class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        int x1=coordinates[0][0],x2=coordinates[1][0];
        int y1=coordinates[0][1],y2=coordinates[1][1];
        int a=x2-x1;
        int b=y2-y1;
        for(int i=2; i<n; i++){
            int x=coordinates[i][0];
            int y=coordinates[i][1];
            if(a*(y-y1)!=b*(x-x1))
                return false;
        }
        return true;
    }
};