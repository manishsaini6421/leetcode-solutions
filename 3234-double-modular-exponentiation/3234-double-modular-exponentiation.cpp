class Solution {
public:

    int pow(int x,int y,int z){
        int res=1;
        for(int i=1; i<=y; i++){
            res=(res*x)%z;
        }
        return res;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        int n=variables.size();
        vector<int> res;
        for(int i=0; i<n; i++){
            int a=variables[i][0];
            int b=variables[i][1];
            int c=variables[i][2];
            int m=variables[i][3];
            
            if(pow(pow(a,b,10),c,m)==target) res.push_back(i);
        }
        return res;
    }
};