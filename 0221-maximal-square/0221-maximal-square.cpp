class Solution {
public:
    void solveOpt(vector<vector<char>>& mat,int &maxi){
        
        int n=mat.size();
        int m=mat[0].size();
        
        vector<int> prev(m,0);
        vector<int> curr(m,0);
        
        for(int j=0; j<m; j++){
            prev[j]=(mat[0][j]=='1')?1:0;
            maxi=max(maxi,prev[j]);
        }
        
        for(int i=1; i<n; i++){
            curr[0]=(mat[i][0]=='1')?1:0;
            maxi=max(maxi,curr[0]);
            
            for(int j=1; j<m; j++){
                
                if(mat[i][j]=='1')
                    curr[j]=1+min(prev[j],min(prev[j-1],curr[j-1]));
                else 
                    curr[j]=0;
                    
                maxi=max(maxi,curr[j]);
            }
            prev=curr;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;

        solveOpt(matrix,ans);

        return ans*ans;
    }
};