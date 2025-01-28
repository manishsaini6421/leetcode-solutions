class Solution {
public:
    bool isValid(vector<vector<bool>> &board,int row,int col){
        int n=board.size();
        for(int i=0; i<row; i++){
            if(board[i][col])return false;
        }
        int i=row,j=col;
        while(i>=0 && j<n){
            if(board[i][j])return false;
            i--;
            j++;
        }
        i=row,j=col;
        while(j>=0 && i>=0){
            if(board[i][j])return false;
            i--;
            j--;
        }
        return true;
    }
    void count(vector<vector<bool>> &board,int &ans,int row){
        int n=board.size();
        if(row==n){
            ans++;
            return;
        }
        for(int i=0; i<n; i++){
            if(isValid(board,row,i)){
                board[row][i]=true;
                count(board,ans,row+1);
                board[row][i]=false;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<bool>> board(n,vector<bool>(n,false));
        int ans=0;
        count(board,ans,0);
        return ans;
    }
};