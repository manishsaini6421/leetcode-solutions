class Solution {
public:
    bool isSafe(vector<vector<char>> board,int row,int col){
        for(int i=0; i<board.size(); i++){
            if(board[i][col]=='Q') return false;
            if(board[row][i]=='Q') return false;
        }
        
        //top left
        int j=col;
        for(int i=row; i>=0 && j>=0; i--,j--){
              if(board[i][j]=='Q') return false;
        }
        
        
        //top right
        j=col;
         for(int i=row; i>=0 && j<board.size(); i--,j++){
              if(board[i][j]=='Q') return false;
        }
        
        //bottom left
        j=col;
         for(int i=row; i<board.size() && j>=0; i++,j--){
              if(board[i][j]=='Q') return false;
        }
        
        //bottom right
        j=col;
         for(int i=row; i<board.size() && j<board.size(); i++,j++){
              if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void helper(int &ans, vector<vector<char>> board,int col){
        if(col == board.size()){
           
            ans++;
            return;
        }
        
        for(int i=0; i<board.size(); i++){
            if(isSafe(board,i,col)){
                board[i][col]='Q';
                helper(ans,board,col+1);
                board[i][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<vector<char>> board(n,vector<char> (n,'.'));
        helper(ans,board,0);
        return ans;
    }
};