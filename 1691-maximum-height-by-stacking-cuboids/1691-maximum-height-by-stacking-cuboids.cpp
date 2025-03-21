class Solution {
public:
    
    int solve(vector<vector<int>>& cuboids, int index, vector<int>& prev) {
        if (index == cuboids.size())
            return 0;

        int w = cuboids[index][0], l = cuboids[index][1],h = cuboids[index][2];
        
        int include=0;

        if(w>=prev[0] && l>=prev[1] && h>=prev[2]){
            include=h+solve(cuboids,index+1,cuboids[index]);
        }
        int exclude=solve(cuboids,index+1,prev);

        return max(include,exclude);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid:cuboids){
            sort(cuboid.begin(),cuboid.end());
        }
        sort(cuboids.begin(),cuboids.end());

        vector<int> v={0,0,0};
        return solve(cuboids,0,v);
          
    }
};