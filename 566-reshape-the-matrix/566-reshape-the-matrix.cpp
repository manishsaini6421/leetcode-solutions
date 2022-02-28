class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans;
        vector<int> temp;
        int m=mat.size();
        int n=mat[0].size();  
        int k=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                temp.push_back(mat[i][j]);
            }
        }
        if(r*c != m*n){
           r=m;
           c=n; 
        }
        
        for(int i=0; i<r; i++){
            vector<int> t;
            for(int i=0; i<c; i++){
                t.push_back(0);
            }
            ans.push_back(t);
            t.clear();
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ans[i][j]=temp[k++];
            }
            
        }
        return ans;
    }
};