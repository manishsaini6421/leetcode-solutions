class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> row;
        vector<int> colom;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    colom.push_back(j);
                }
            }
        }
        for(auto i:row){
            for(int j=0; j<n; j++){
                matrix[i][j]=0;
            }
            
        }
        for(auto j:colom){
            for(int i=0; i<m; i++){
                matrix[i][j]=0;
            }
        }
    }
};