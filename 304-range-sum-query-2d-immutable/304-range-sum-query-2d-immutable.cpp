class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0; i<m; i++){
            vector<int> v(n);
            v[0]=matrix[i][0];
            for(int j=1; j<n; j++){
                v[j]=v[j-1]+matrix[i][j];
            }
            mat.push_back(v);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0; 
        int minus=0;
        for(int i=row1; i<=row2; i++){
            sum+=mat[i][col2];
            if(col1>0){
                minus+=mat[i][col1-1];
            }
        }
        return sum-minus;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */