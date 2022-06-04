class Solution {
public:
    bool isSafe(vector<vector<char>> &board,int row, int col){
        for(int i=0; i<board.size(); i++){
            if(board[row][i]=='Q') return false;
            if(board[i][col]=='Q') return false;
        }
        
        
        //top left 
        int j=col;
        for(int i=row; i>=0 && j>=0; i--,j--){
            if(board[i][j]=='Q') return false;
        }
        
        //top right
        j=col;
        for(int i=row; i>=0 && j<board[0].size(); i--,j++){
            if(board[i][j]=='Q') return false;
        }
        
        //bottom left
        j=col;
        for(int i=row; i<board.size() && j>=0; i++,j--){
            if(board[i][j]=='Q') return false;
        }
        
        //bottom right
        j=col;
        for(int i=row; i<board.size() && j<board[0].size(); i++,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    
    void saveBoard(vector<vector<string>>&ans, vector<vector<char>> &board){
       vector<string> v;
        for(int i=0; i<board.size(); i++){
             string s="";
            for(int j=0; j<board[0].size(); j++){
                s+=board[i][j];
            }
            v.push_back(s);
        }
        ans.push_back(v);
    }
    
    void helper(vector<vector<string>>&ans, vector<vector<char>> &board, int col){
       
        if(col==board.size()) {
            saveBoard(ans,board);
            return;
    }
       for(int row=0; row<board.size(); row++){
          if(isSafe(board,row,col)){
               board[row][col]='Q';
               helper(ans,board,col+1);
               board[row][col]='.';
           }
       }
        
        
    }
    
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n,vector<char> (n,'.'));
        helper(ans,board,0);
        return ans;
    }
    
};