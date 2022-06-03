class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,int number){
        for(int i=0; i<9; i++){
            if(board[i][col]==number+'0') return false;
            if(board[row][i]==number+'0') return false;
            
        }
          int sr=(row/3)*3;
            int sc=(col/3)*3;
            
            for(int i=sr; i<sr+3; i++){
                for(int j=sc; j<sc+3; j++){
                    if(board[i][j]==number+'0') return false;
                }
            }
        return true;
    }
    bool helper(vector<vector<char>>& board,int row,int col){
        if(row==9) return true;
        
        int nrow=0; 
        int ncol=0;
        
        if(col !=8){
            ncol=col+1;
            nrow=row;
        }
        else{
            nrow=row+1;
            ncol=0;
        }
        
        if(board[row][col] !='.'){
            if(helper(board,nrow,ncol)) return true;
        }
        else{
            for(int i=1; i<=9; i++){
                if(isSafe(board,row,col,i)){
                    board[row][col]=i+'0';
                    if(helper(board,nrow,ncol)) return true;
                    else board[row][col]='.';
                } 
                
            }
        }
        return false;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
     helper(board,0,0);
       
    }
};