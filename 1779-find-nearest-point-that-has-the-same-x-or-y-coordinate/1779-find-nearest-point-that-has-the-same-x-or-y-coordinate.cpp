class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n=points.size();
        
        int res=-1;
        
        int minDis=INT_MAX;
        for(int i=0; i<n; i++){
            if(x==points[i][0]  || y==points[i][1]){
              int dis=abs(x-points[i][0])+abs(y-points[i][1]);
                if(dis<minDis){
                    minDis=dis;
                    res=i;
                }
            }
        }
        
       
      
        return res;
    }
};